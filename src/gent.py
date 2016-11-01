import sys
import os
import shutil
import random
import copy
import subprocess
import prog_monkey, prog_monkey_csmith, runner, gen_csmith, coverage

MIN = 1
MAX = 100
OUT_1 = 'out.cpachecker'
OUT_2 = 'out.cbmc'
TIMELIMIT = 90
N_UNWIND = 50
mc1_cmd = './cpa.sh -preprocess -timelimit ' + str(TIMELIMIT) + ' -valueAnalysis '
mc2_cmd = 'timeout ' + str(TIMELIMIT) + ' ./cbmc --unwind ' + str(N_UNWIND) + ' --no-unwinding-assertions '

CONFIG = ["--no-argc", "--no-bitfields", "--no-checksum", "--no-comma-operators",
			"--no-compound-assignment", "--no-consts", "--no-divs", "--no-embedded-assigns", 
			"--no-pre-incr-operator", "--no-pre-decr-operator", "--no-post-incr-operator", 
			"--no-post-decr-operator", "--no-unary-plus-operator", "--no-jumps", "--no-longlong", 
			"--no-int8", "--no-uint8", "--no-math64", "--no-inline-function", 
			"--no-muls", "--no-safe-math", "--no-packed-struct", "--no-paranoid", 
			"--no-volatile-pointers", "--no-const-pointers", 
			"--no-builtins"]

class MCMCInfo:
	def __init__(self, config, cov):
		self.config = config
		self.cov = cov

def mutate(config):
	return gen_csmith.fuzz_flags(config)

# generate a program using a config of Csmith
def genProg(config, gen_dir):
	prefix = 'gen_csmith_'
	extension = '.c'
	rand = random.randint(MIN, MAX)
	fname = os.path.join(gen_dir, prefix + str(rand) + extension)
	gen_csmith.run_Csmith(rand, config, fname)
 	return fname

# update the current config based on mcmc
def generate_mcmc(current, cov):
	rand = random.randint(MIN, MAX)
	if current.cov == 0:
		accept = MAX + 1
	else:
		accept = (cov / current.cov) * MAX
	
	if rand <= min(100, accept):
		current.cov = cov
		current.config = mutate(CONFIG)

	return current

def size_control(seed, size):
	count = 0
	for f in os.listdir(seed):
		count += 1
		if count <= size:
			continue
		os.remove(os.path.join(seed, f))

# synthesize a set of test inputs given a program
def synthesize(prog, preprocess, seed):
	fname = os.path.basename(prog)
	fpath = os.path.join(preprocess, 'tmp/')
	prog_monkey_csmith.generate(fname, fpath, seed)
	size_control(seed, 3)
	
	n = len([name for name in os.listdir(seed)])

	return n

# validate 2 model checkers given a set of test inputs
def validate(mc1, mc2, output, found, seed):
	high = 0
	gcov_log = os.path.abspath(os.path.join(seed, os.pardir))
	for root, dirs, files in os.walk(seed):
		for f in files:
			if (not f.endswith('.c')) and (not f.endswith('.i')):
				continue
			fname = os.path.join(seed, f)
			os.chdir(mc1)
			output_mc1 = os.path.join(output, OUT_1)
			rc_mc1 = subprocess.call(mc1_cmd + fname + ' > ' + output_mc1, shell=True)
			os.chdir(mc2)
			output_mc2 = os.path.join(output, OUT_2)
			rc_mc2 = subprocess.call(mc2_cmd + fname + ' > ' + output_mc2, shell=True)
			
			cov = coverage.collect(mc2, gcov_log)
			if cov > high:
				high = cov

			result1 = runner.extract_verification_result(output_mc1)
			result2 = runner.extract_verification_result(output_mc2)

			if result1 != result2:
				print '**** an inconsistency is found: ' + f
				shutil.copy(os.path.join(seed, f), found)

	return high
					

def run_gent_fake(N, mc_1, mc_2, log):
	dirname = os.path.dirname(os.path.realpath(__file__))
	print os.path.abspath(os.path.join(dirname, os.pardir))


def initialize():
	return MCMCInfo(CONFIG, 0)

def clean(seed):
	fs = os.listdir(seed)
	for f in fs:
		os.remove(os.path.join(seed, f))

# main entry
# mc_1: cpachecker; mc_2: cbmc
def run_gent(N, mc_1, mc_2):
	print '## GenT starts a validation ##'
	
	current = initialize()
	
	dirname = os.path.dirname(os.path.realpath(__file__))
	root = os.path.abspath(os.path.join(dirname, os.pardir))

	mc1 = os.path.abspath(mc_1)
	mc2 = os.path.abspath(mc_2)
	output = os.path.join(root, 'src/tmp/output/')
	found = os.path.join(root, 'src/tmp/found/')
	seed = os.path.join(root, 'src/tmp/seeds/')

	for i in range(0, N):
		print '## iteration ' + str(i)
		clean(seed)
		print '## seed directory cleaned'
		test_dir = os.path.join(root, 'src/tmp/')
		testName = genProg(current.config, test_dir)
		
		print '++ ' + testName + ' generated'
		rc = synthesize(testName, dirname, seed)
		print '++ ' + str(rc) + ' test inputs synthesized'
		if rc is 0:
			continue
		cov = validate(mc1, mc2, output, found, seed)
		print '++ validation completed'
		current = generate_mcmc(current, cov)
		print '++ configuration updated'
		print '--------------------------------------------------------------'

	print '## GenT completed ##'


#------------------------------------------------------------------------------
if __name__ == "__main__":
	if len(sys.argv) != 4:
		print("\nUsage:\n    gent.py N mc-1 mc-2\n")
	else:
		run_gent(int(sys.argv[1]), sys.argv[2], sys.argv[3])
