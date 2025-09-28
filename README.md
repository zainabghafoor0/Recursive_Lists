**Name:** Zainab Ghafoor  
**ID:** 008259427  
**GitHub repository link:** [[https://github.com/zainabghafoor0/Recursive_Lists.git](https://github.com/zainabghafoor0/Recursive_Lists.git)]

## Project Description
This repository implements a **recursive list** toolkit (Lisp-style `car`/`cdr`/`cons`) and a suite of list-processing functions in **pure recursion** (no loops).  
Lists are read in S-expression form using the provided ADT; atoms are 1–8 letters and `()` denotes the empty list.  
Implemented capabilities include flattening, deep reversal, structural equality, set operations, substitution, subset checks, and (extra credit) permutations—each composed solely from the ADT primitives and `if/else`.

## Collaboration & Sources 
- **Work:** All functions in `solutions.cpp/.hpp` written and tested by me; no external code or libraries used.

## Implementation Details
**Build**
```bash
g++ -std=c++17 -Wall -Wextra -O2 \
  main.cpp reclists.cpp parser.cpp lex.cpp solutions.cpp \
  -o recursive_lists\
 .\recursive_lists
# I updated the main_test.cpp file, where I test all the functions. To run it, use the below command.
g++ -std=c++17 -Wall -Wextra -O2 \
  main_test.cpp reclists.cpp parser.cpp lex.cpp solutions.cpp \
  -o recursive_lists_test \
  .\recursive_lists_test
