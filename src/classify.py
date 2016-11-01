import os, sys, subprocess, re

TIMELIMIT = 45
EXT = '.cpp'
GCOV_EXT = '.cpp.gcov'
DELIMETER = ' --- '
N = 10
MIN_LOC = 0

# Run gcov for files in the specified directory
def gen_gcov(gcov):
	os.chdir(gcov)
	for root, dirs, files in os.walk(gcov):
		for f in files:
			if f.endswith(EXT):
				print 'generate gcov file for ' + f
				subprocess.call('gcov ' + f, shell=True)


# Get a spectrum for a single file
def process_single_file(fi):
	spectrum = ''
	f = open(fi, 'r')
	for line in f:
		count = line.split(':')[0]
		flag = any(char.isdigit() for char in count)
		#num = re.findall('\d+', count)
		# print 'COUNT: ' + count
		if flag is True:
			spectrum += '1'
			#spectrum += num
			# print 'aliualiu'
		else:
			spectrum += '0'
	f.close()

	return spectrum

# Get a spectrum for all files in the specified directory
def gen_spectrum(gcov):
	spectrum = ''
	for root, dirs, files in os.walk(gcov):
		for f in files:
			if f.endswith(GCOV_EXT):
				print 'processing gcov file ' + f
				loc = sum(1 for l in open(os.path.join(root, f)))
				print 'loc is ' + str(loc)
				if loc < MIN_LOC:
					continue
				spectrum += process_single_file(os.path.join(root, f))
	return spectrum

# find the pass/fail testbases based on a log file
def find_record(log, mode):
	result = []
	f = open(log, 'r')
	i = 0
	for line in f:
		if i >= N:
			break
		if mode == 'good':
			if (line.count('SUCCESS') == 2) or (line.count('FAIL') == 2):
				result.append(line.split()[0])
				i += 1
		if mode == 'bad':
			if (line.count('SUCCESS') == 1) or (line.count('FAIL') == 1):
				result.append(line.split()[0])
				i += 1
	f.close()

	return result


'''
   log: full path of the log file
   base: path to the directory which contains all the source file
   mc_dir: path to the model checker directory
   gcov: path to the directory where we run gcov
'''
def classify(log, base, mc_dir, gcov):
	os.chdir(mc_dir)
	info_good = []
	info_bad = []
	good = find_record(log, 'good')
	for f in good:
		fname = base + f
		subprocess.call("timeout " + str(TIMELIMIT) + " ./cbmc --unwind 20 --no-unwinding-assertions " + fname, shell=True)
		gen_gcov(gcov)
		spectrum = gen_spectrum(gcov)
		print f + DELIMETER + spectrum
		record = {'id': fname, 'spec': spectrum, 'outcome': 'true'}
		info_good.append(record)
	bad = find_record(log, 'bad')
	for f in bad:
		fname = base + f
		subprocess.call("timeout " + str(TIMELIMIT) + " ./cbmc --unwind 20 --no-unwinding-assertions " + fname, shell=True)
		gen_gcov(gcov)
		spectrum = gen_spectrum(gcov)
		print f + DELIMETER + spectrum
		record = {'id': fname, 'spec': spectrum, 'outcome': 'false'}
		info_bad.append(record)

	print '### good: ' + str(len(info_good))
	print '### bad: ' + str(len(info_bad))
	# print info_good[0]['spec']
	for l in info_good:
		print len(l['spec'])
		print l['spec']
	for l in info_bad:
		print len(l['spec'])
		print l['spec']
	
	return {'good': info_good, 'bad': info_bad}


#------------------------------------------------------------------------------
if __name__ == "__main__":
	if len(sys.argv) != 5:
		print("\nUsage:\n    python classify.py testsuit-file source-base-directory mc-directory gcov-directory\n")
	else:
		classify(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4])