import sys
import os
import copy
from pycparser import c_parser, c_generator, c_ast, parse_file

class MetaData:
	def __init__(self, now, target):
		self.now = now
		self.target = target

def deepInsert(ast):
	ast.ext[0].show()
	target = countAllInsertion(ast.ext[0].body)
	meta = MetaData(0, target)
	ast.ext[0].body = explore(ast.ext[0].body, meta)
	code_new = c_generator.CGenerator().visit(ast)
	print code_new
	print "Total is: " + str(target)

# insert an error label at a specified location based on meta
def explore(node, meta, error_label):
	if isinstance(node, c_ast.Compound):
		if not (node.block_items is None):
			for i in range(0, len(node.block_items)):
				child = node.block_items[i]
				node.block_items[i] = explore(child, meta, error_label)
		else:
			meta.now += 1
			if meta.now == meta.target:
				com = [error_label]
				node = c_ast.Compound(com)
	elif isinstance(node, c_ast.Case) or isinstance(node, c_ast.Default):
		if not (node.stmts is None):
			for i in range(0, len(node.stmts)):
				child = node.stmts[i]
				node.stmts[i] = explore(child, meta, error_label)
		else:
			meta.now += 1
			if meta.now == meta.target:
				com = [error_label]
				node = c_ast.Compound(com)
	elif isinstance(node, c_ast.If):
		node.iftrue = explore(node.iftrue, meta, error_label)
		if not (node.iffalse is None):
			node.iffalse = explore(node.iffalse, meta, error_label)
	elif isinstance(node, c_ast.Switch):
		node.stmt = explore(node.stmt, meta, error_label)
	elif isinstance(node, c_ast.While):
		node.stmt = explore(node.stmt, meta, error_label)
	elif isinstance(node, c_ast.DoWhile):
		node.stmt = explore(node.stmt, meta, error_label)
	elif isinstance(node, c_ast.For):
		node.stmt = explore(node.stmt, meta, error_label)
	elif isinstance(node, c_ast.Label):
		node.stmt = explore(node.stmt, meta, error_label)
	else:
		meta.now += 1
		if meta.now == meta.target:
			com = [error_label, copy.deepcopy(node)]
			node = c_ast.Compound(com)

	return node

# count the total number of possible insertions
def countAllInsertion(node, count):
	if isinstance(node, c_ast.Compound):
		if not (node.block_items is None):
			for i in range(0, len(node.block_items)):
				child = node.block_items[i]
				count = countAllInsertion(child, count)
		else:
			count += 1
	elif isinstance(node, c_ast.Case) or isinstance(node, c_ast.Default):
		if not (node.stmts is None):
			for i in range(0, len(node.stmts)):
				child = node.stmts[i]
				count = countAllInsertion(child, count)
		else:
			count += 1
	elif isinstance(node, c_ast.If):
		count = countAllInsertion(node.iftrue, count)
		if not (node.iffalse is None):
			count = countAllInsertion(node.iffalse, count)
	elif isinstance(node, c_ast.Switch):
		count = countAllInsertion(node.stmt, count)
	elif isinstance(node, c_ast.While):
		count = countAllInsertion(node.stmt, count)
	elif isinstance(node, c_ast.DoWhile):
		count = countAllInsertion(node.stmt, count)
	elif isinstance(node, c_ast.For):
		count = countAllInsertion(node.stmt, count)
	elif isinstance(node, c_ast.Label):
		count = countAllInsertion(node.stmt, count)
	else:
		count += 1
	
	return count

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

# insert an error label at a specified location based on meta
def explore_bak(node, meta, error_label):
	if isinstance(node, c_ast.Compound):
		if not (node.block_items is None):
			for i in range(0, len(node.block_items)):
				child = node.block_items[i]
				if isinstance(child, c_ast.Compound):
					child = explore(child, meta, error_label)
				elif isinstance(child, c_ast.If):
					child.iftrue = explore(child.iftrue, meta, error_label)
					if not (child.iffalse is None):
						child.iffalse = explore(child.iffalse, meta, error_label)
				elif isinstance(child, c_ast.Switch):
					child.stmt = explore(child.stmt, meta, error_label)
				elif isinstance(child, c_ast.While):
					child.stmt = explore(child.stmt, meta, error_label)
				elif isinstance(child, c_ast.DoWhile):
					child.stmt = explore(child.stmt, meta, error_label)
				elif isinstance(child, c_ast.For):
					child.stmt = explore(child.stmt, meta, error_label)
				elif isinstance(child, c_ast.Label):
					child.stmt = explore(child.stmt, meta, error_label)
				else:
					meta.now += 1
					if meta.now == meta.target:
						com = [error_label, copy.deepcopy(child)]
						node.block_items[i] = c_ast.Compound(com)
		else:
			meta.now += 1
			if meta.now == meta.target:
				com = [error_label]
				node = c_ast.Compound(com)
	elif isinstance(node, c_ast.If):
		node.iftrue = explore(node.iftrue, meta, error_label)
		if not (node.iffalse is None):
			node.iffalse = explore(node.iffalse, meta, error_label)
	elif isinstance(node, c_ast.Switch):
		node.stmt = explore(node.stmt, meta, error_label)
	elif isinstance(node, c_ast.While):
		node.stmt = explore(node.stmt, meta, error_label)
	elif isinstance(node, c_ast.DoWhile):
		node.stmt = explore(node.stmt, meta, error_label)
	elif isinstance(node, c_ast.For):
		node.stmt = explore(node.stmt, meta, error_label)
	elif isinstance(node, c_ast.Label):
		node.stmt = explore(node.stmt, meta, error_label)
	else:
		meta.now += 1
		if meta.now == meta.target:
			com = [error_label, copy.deepcopy(node)]
			node = c_ast.Compound(com)

	return node

# count the total number of possible insertions
def countAllInsertion_bak(node, count):
	if isinstance(node, c_ast.Compound):
		if not (node.block_items is None):
			for i in range(0, len(node.block_items)):
				child = node.block_items[i]
				if isinstance(child, c_ast.Compound):
					count = countAllInsertion(child, count)
				elif isinstance(child, c_ast.If):
					count = countAllInsertion(child.iftrue, count)
					if not (child.iffalse is None):
						count = countAllInsertion(child.iffalse, count)
				elif isinstance(child, c_ast.Switch):
					count = countAllInsertion(child.stmt, count)
				elif isinstance(child, c_ast.While):
					count = countAllInsertion(child.stmt, count)
				elif isinstance(child, c_ast.DoWhile):
					count = countAllInsertion(child.stmt, count)
				elif isinstance(child, c_ast.For):
					count = countAllInsertion(child.stmt, count)
				elif isinstance(child, c_ast.Label):
					count = countAllInsertion(child.stmt, count)
				else:
					count += 1
		else:
			count += 1
	elif isinstance(node, c_ast.If):
		count = countAllInsertion(node.iftrue, count)
		if not (node.iffalse is None):
			count = countAllInsertion(node.iffalse, count)
	elif isinstance(node, c_ast.Switch):
		count = countAllInsertion(node.stmt, count)
	elif isinstance(node, c_ast.While):
		count = countAllInsertion(node.stmt, count)
	elif isinstance(node, c_ast.DoWhile):
		count = countAllInsertion(node.stmt, count)
	elif isinstance(node, c_ast.For):
		count = countAllInsertion(node.stmt, count)
	elif isinstance(node, c_ast.Label):
		count = countAllInsertion(node.stmt, count)
	else:
		count += 1
	
	return count