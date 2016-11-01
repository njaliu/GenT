import sys
import os
import random
import subprocess

'''
DISABLED = ["--no-argc", "--no-arrays", "--no-bitfields", "--no-checksum", "--no-comma-operators",
			"--no-compound-assignment", "--no-consts", "--no-divs", "--no-embedded-assigns", 
			"--no-pre-incr-operator", "--no-pre-decr-operator", "--no-post-incr-operator", 
			"--no-post-decr-operator", "--no-unary-plus-operator", "--no-jumps", "--no-longlong", 
			"--no-int8", "--no-uint8", "--no-float", "--no-math64", "--no-inline-function", 
			"--no-muls", "--no-safe-math", "--no-packed-struct", "--no-paranoid", "--no-pointers", 
			"--no-structs", "--no-unions", "--no-volatiles", "--no-volatile-pointers", "--no-const-pointers", 
			"--no-builtins"]
'''
# with arrays, floats, pointers, structs, unions, volatiles
DISABLED = ["--no-argc", "--no-bitfields", "--no-checksum", "--no-comma-operators",
			"--no-compound-assignment", "--no-consts", "--no-divs", "--no-embedded-assigns", 
			"--no-pre-incr-operator", "--no-pre-decr-operator", "--no-post-incr-operator", 
			"--no-post-decr-operator", "--no-unary-plus-operator", "--no-jumps", "--no-longlong", 
			"--no-int8", "--no-uint8", "--no-math64", "--no-inline-function", 
			"--no-muls", "--no-safe-math", "--no-packed-struct", "--no-paranoid", 
			"--no-volatile-pointers", "--no-const-pointers", 
			"--no-builtins"]

CMD = "csmith -s "
SIZE_CTRL = " --max-funcs 3 --max-block-size 3"
PREFIX = "gent_"
CSMITH_LIB = "/home/aliu/Research/Projects/csmith-2.2.0/runtime"
PREPROCESS_CMD = "gcc -E -I " + CSMITH_LIB + " "
MIN = 1000
MAX = 2000


def run_Csmith(seed, config, fname):
	gen_cmd = CMD + str(seed) + " " + concat_flags(config) + SIZE_CTRL + " -o " + fname
	subprocess.call(gen_cmd, shell=True)

def fuzz_flags(flags):
	#num = random.randint(1, len(flags)) # select a random group of flags
	num = len(flags)
	print num
	selected = random.sample(flags, num)
	return selected

def concat_flags(config):
	result = ""
	for c in config:
		result = result + " " + c
	return result

def run(N, preprocess_dir, generate_dir):
	for i in range(0, N):
		config = fuzz_flags(DISABLED)
		options = concat_flags(config)
		seed = random.randint(MIN, MAX)
		base = PREFIX + "iteration-" + str(i) + "_seed-" + str(seed)
		fname = base + ".c"
		full_name = generate_dir + fname
		gen_cmd = CMD + str(seed) + " " + options + SIZE_CTRL + " -o " + full_name
		subprocess.call(gen_cmd, shell=True)
		print("#### Generate " + full_name)
		full_pre_name = preprocess_dir + base + ".i"
		pre_cmd = PREPROCESS_CMD + full_name + " > " + full_pre_name
		# subprocess.call(pre_cmd, shell=True)
		# print("#### Preprocess " + full_pre_name)

	print "#### Finish"


#------------------------------------------------------------------------------
if __name__ == "__main__":
	if len(sys.argv) == 4:
		run(int(sys.argv[1]), sys.argv[2], sys.argv[3])
	else:
		print("\nUsage: \n    gen_csmith.py number_of_files preprocess_dir generate_dir\n")

#print concat_flags(fuzz_flags(DISABLED))