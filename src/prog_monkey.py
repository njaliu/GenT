import sys
import os
import random
import copy
import subprocess

from pycparser import c_parser, c_generator, c_ast, parse_file
import algo

postfix = "_gen_"
LIB_INCLUDE = "/home/aliu/Research/Projects/pycparser/utils/fake_libc_include"
#LIB_INCLUDE = "/home/aliu/Downloads/itc-benchmarks-master/include" # The itc-bench include
PP_CMD = "gcc -E "
ERROR_str = "ERROR: __VERIFIER_error();"
ATTRIBUTE_str = "__attribute__ ((__noreturn__))"
NON_SUPPORT_FEATURES = ["typedef int __builtin_va_list;"]

# generate the to-be-verified files given an input file
def generate(code, origin_file, gen_path):
	parser = c_parser.CParser()
	ast = parser.parse(code)

	# construct an error label
	checkpoint = c_ast.FuncCall(c_ast.ID('__VERIFIER_error'), None)
	error_label = c_ast.Label("ERROR", checkpoint)

	num_ext_children = len(ast.ext)
	print("## num of ext children: " + str(num_ext_children))
	funcs = findAllFuncDef(ast)

	for picked in funcs:
		# picked = random.randint(0, len(funcs)-1)
		seed_fun = funcs.index(picked)
		print("## Function picked: " + str(seed_fun))
		seed = ast.ext.index(picked)
		print("## Seed: " + str(seed))

		numInsert = algo.countAllInsertion(ast.ext[seed].body, 0)
		print("$$$$$ numInsert is " + str(numInsert))
		for i in range(1, numInsert+1):
			ast_new = copy.deepcopy(ast)
			ast_new.ext[seed].body = checkpoint_insert_if(ast_new.ext[seed].body, i, error_label)
			code_new = c_generator.CGenerator().visit(ast_new)
			basename = origin_file
			basename_gen, file_extension = os.path.splitext(basename)
			filename_gen = gen_path + basename_gen + postfix + str(seed_fun) + '-' + str(i) + file_extension
			dumpToFile(filename_gen, code_new)
			print("## Generate: " + filename_gen)


'''
		iterations = len(picked.body.block_items)
		for pos in range(0, iterations+1):
			ast_new = checkpoint_insert(seed, ast, pos, error_label)
			code_new = c_generator.CGenerator().visit(ast_new)
			basename = origin_file
			basename_gen, file_extension = os.path.splitext(basename)
			filename_gen = gen_path + basename_gen + postfix + str(seed_fun) + '-' + str(pos) + file_extension
			dumpToFile(filename_gen, code_new)
			print("## Generate: " + filename_gen)
'''

# insert an error label with a given position, targeting at IF structure
def checkpoint_insert_if(body, pos, error_label):
	meta = algo.MetaData(0, pos)
	return algo.explore(body, meta, error_label)

# insert an error label with a given position
def checkpoint_insert(seed, ast, pos, error_label):
	ast_new = copy.deepcopy(ast)
	func = ast_new.ext[seed]
	if(type(func) == c_ast.FuncDef):
		func.body.block_items.insert(pos, error_label)
		print("## Checkpoint insertion: " + str(pos) + " at " + func.decl.name)
	else:
		print("## Error: non-function checkpoint insertion.")

	return ast_new

# randomly insert an error label into a function
def checkpoint_random(seed, ast, error_label):
	chunk = ast.ext[seed]
	if(type(chunk) == c_ast.FuncDef):
		seed_pos = random.randint(0, len(chunk.body.block_items)-1)
		chunk.body.block_items.insert(seed_pos, error_label)
		print("## Checkpoint insertion: " + str(seed_pos) + " at " + chunk.decl.name)
	else:
		# seed_pos = ast.ext.index(chunk)
		# ast.ext.insert(seed_pos, checkpoint)
		print("## Error: non-function checkpoint insertion.")

	return ast

def findAllFuncDef(ast):
	funcs = []
	for node in ast.ext:
		if(type(node) == c_ast.FuncDef):
			funcs.append(node)
	return funcs

# preprocess a file using gcc
def preprocess(origin_file, preprocess_path):
	basename = os.path.basename(origin_file)
	filename_pp = preprocess_path + basename
	subprocess.call(PP_CMD + origin_file + " -I " + LIB_INCLUDE + " > " + filename_pp, shell=True)

# dump the generated code to a file
def dumpToFile(filename, gen_code):
	with open(filename, 'w+') as fw:
		fw.write(gen_code)
		fw.close()

def removeNonSupport(code):
	code = code.replace(ERROR_str, "") # remove the existing ERROR label
	code = code.replace(ATTRIBUTE_str, "")
	for ns in NON_SUPPORT_FEATURES: # remove the non-support features
		code = code.replace(ns, "") 
	return code

def run(origin_path, preprocess_path, gen_path):
	num = 0
	for root, dirs, files in os.walk(origin_path):
		for f in files:
			if f.endswith(".c") or f.endswith(".i"):
				num += 1
				try:
					preprocess(os.path.join(root, f), preprocess_path)
					with open(os.path.join(preprocess_path, f), 'r') as fr:
						before = fr.read()
						before_noErr = removeNonSupport(before) # remove the non-supported features
						fr.close()
						generate(before_noErr, f, gen_path)
				except:
					pass
	print("\n%d file processed!\n" % num)


#------------------------------------------------------------------------------
if __name__ == "__main__":
	if len(sys.argv) == 4:
		run(sys.argv[1], sys.argv[2], sys.argv[3])
	else:
		print("\nUsage: \n    prog_monkey.py origin_dir preprocess_dir generate_dir\n")
