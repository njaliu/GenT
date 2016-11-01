import sys
import os
import subprocess

SUCCESS = 'SUCCESS'
FAIL = 'FAIL'

def check(out1, out2):
	if (out1 == SUCCESS) and (out2 == FAIL):
		return True
	if (out1 == FAIL) and (out2 == SUCCESS):
		return True
	else:
		return False

def process(log, source, collection):
	f = open(log, 'r')
	for line in f:
		record = line.split()
		if check(record[1], record[2]) is True:
			print source + record[0]
			subprocess.call('cp ' + source + record[0] + ' ' + collection, shell=True)
	f.close()


#------------------------------------------------------------------------------
# Process a log file, identify the inconsistency record, copy the input to the collection directory
if __name__ == "__main__":
	if len(sys.argv) != 4:
		print("\nUsage:\n    python process_log.py path-of-log-file source-directory collection-directory\n")
	else:
		process(sys.argv[1], sys.argv[2], sys.argv[3])