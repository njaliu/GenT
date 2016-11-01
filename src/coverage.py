import os, sys, subprocess, re

MAIN_FILE = 'cbmc_main.cpp'
GCOV_CMD = 'gcov' + ' ' + MAIN_FILE


def parse(line):
	pattern = '.*:(\d+\.\d+%) of (\d+)'
	m = re.search(pattern, line)
	ratio = m.group(1)
	cov = int(m.group(2))
	if ratio != '0.00%':
		return cov
	return 0

def calculate(log):
	cov = 0
	marker = 'Lines executed:'
	with open(log, 'r') as f:
		for line in f:
			if marker not in line:
				continue
			cov += parse(line)

	print '-- coverage is: ' + str(cov)
	return cov

def collect(mc, gcov):
	os.chdir(mc)
	gcov_log = os.path.abspath(os.path.join(gcov, 'gcov.log'))
	subprocess.call(GCOV_CMD + ' > ' + gcov_log, shell=True)
	cov = calculate(gcov_log)
	return cov