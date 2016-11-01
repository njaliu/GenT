import sys
import os
import subprocess

output_cpachecker = "output_cpachecker/"
output_cbmc = "output_cbmc/"

# Non-exception code. Used for subprocess call
NE_CODE_CPACHECKER = 0
NE_CODE_CBMC = 10
TIMELIMIT = 25

def extract_verification_result(filename):
	f = open(filename, "r")
	result = f.read()
	f.close()
	if "FAILED" in result or "FALSE" in result:
		return "FAIL"
	elif "SUCCESSFUL" in result or "TRUE" in result:
		return "SUCCESS"
	else:
		return "UNKNOWN"

def run_tmc(path_seed, path_output, mc_path_1, mc_path_2, tmc_result_file):
	count = 0
	f_tmc = open(tmc_result_file, 'a')
	f_tmc.write('%50s %20s %20s\n' % ("File", "CPAchecker", "CBMC"))
	f_tmc.close()
	# create the /output_tmc directory
	if not os.path.exists(os.path.join(path_output, output_cpachecker)):
		os.makedirs(os.path.join(path_output, output_cpachecker))
	if not os.path.exists(os.path.join(path_output, output_cbmc)):
		os.makedirs(os.path.join(path_output, output_cbmc))

	for root, dirs, files in os.walk(path_seed):
		for f in files:
			if f.endswith(".c") or f.endswith(".i"):
				print("## Processing %s\n" % f)
				# use CPAchecker for verification
				os.chdir(mc_path_1)
				output_file_1 = os.path.join(path_output, output_cpachecker) + f + ".output"
				rc_cpachecker = subprocess.call("./cpa.sh -preprocess -timelimit " + str(TIMELIMIT) + " -valueAnalysis " + os.path.join(path_seed, f) + " > " + output_file_1, shell=True)
				#if rc_cpachecker != NE_CODE_CPACHECKER:
					#continue
				# use CBMC for verification
				os.chdir(mc_path_2)
				output_file_2 = os.path.join(path_output, output_cbmc) + f + ".output"	
				rc_cbmc = subprocess.call("timeout " + str(TIMELIMIT) + " ./cbmc --unwind 10 --no-unwinding-assertions " + os.path.join(path_seed, f) + " > " + output_file_2, shell=True)
				#rc_cbmc = subprocess.call("timeout " + TIMELIMIT + " ./cbmc --unwind 5 --signed-overflow-check --unsigned-overflow-check --float-overflow-check --nan-check --no-unwinding-assertions " + os.path.join(path_seed, f) + " > " + output_file_2, shell=True)
				#if rc_cbmc != NE_CODE_CBMC:
					#continue
				f_tmc = open(tmc_result_file, 'a')
				f_tmc.write('%50s %20s %20s\n' % (f, extract_verification_result(output_file_1), extract_verification_result(output_file_2)))
				count += 1
				f_tmc.close()
	
	# f_tmc.close()
	print("\n## TMC Finish! Number of seed files: %s\n" % str(count))


#------------------------------------------------------------------------------
if __name__ == "__main__":
	if len(sys.argv) != 6:
		print("\nUsage:\n    python runner.py path_seed path_output mc_path_1 mc_path_2 tmc_result_file\n")
	else:
		run_tmc(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])


# print(extract_verification_result("/home/aliu/cpachecker-result"))