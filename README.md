# Overview

GenT is a tool to validate C model checkers via random test input generation and differential testing techniques.

The repository is organized as follows:

* README.md: this file
* src: source code
* bugs: bugs found in previous validation
* tests: test cases
* mc: model checkers under test (should be manually set)

# Dependencies

* Csmith
* pycparser
* gcov 

# Using GenT

## Set up Csmith

The first step is to set up Csmith and configure it to the bash command. 
To do this, please refer to https://embed.cs.utah.edu/csmith/

## Build the McUT with Gcov

Next, you should build the model checkers under test (McUT) with gcov. 
In our case, we do this on CBMC.

## Start the validation
To do this, use the following command:

$ cd src/

$ python gent.py N MC-1 MC-2 // N is the number of iterations, MC-1/MC-2 is the path to McUT

