**Name:** Zainab Ghafoor  
**ID:** 008259427  
**GitHub repository link:** [[https://github.com/zainabghafoor0/Recursive_Lists.git](https://github.com/zainabghafoor0/Recursive_Lists.git)]

## Project Description
This repository implements a **recursive list** toolkit (Lisp-style `car`/`cdr`/`cons`) and a suite of list-processing functions in **pure recursion** (no loops).  
Lists are read in S-expression form using the provided ADT; atoms are 1–8 letters and `()` denotes the empty list.  
Implemented capabilities include flattening, deep reversal, structural equality, set operations, substitution, subset checks, and (extra credit) permutations—each composed solely from the ADT primitives and `if/else`.

## Collaboration & Sources 
- **Work:** All functions in `solutions.cpp/.hpp` written and tested.

## Implementation Details
**How to Run**
```bash
g++ -std=c++17 -Wall -Wextra -O2 \
  main.cpp reclists.cpp parser.cpp lex.cpp solutions.cpp \
  -o recursive_lists\
 .\recursive_lists
````
I updated the main_test.cpp file, where I test all the functions. To run it, use the below command.
```bash
g++ -std=c++17 -Wall -Wextra -O2 \
  main_test.cpp reclists.cpp parser.cpp lex.cpp solutions.cpp \
  -o recursive_lists_test \
  .\recursive_lists_test

````
Sample output while using main_test.cpp:
----------------------------------------
Choose:
 1) is_lat (list)
 2) member (atom, list)
 3) last (list)
 4) list_pair (list, list)
 5) firsts (list)
 6) flat (list)
 7) two_the_same (list, list)
 8) equal (list, list)
 9) total_reverse (list)
10) shape (list)
11) intersection (list, list)
12) union (list, list)
13) substitute (old_atom, new_atom, list)
14) remove_all (list_of_atoms, atom)
15) subset (list, list)
16) permute (list_of_atoms)
 0) quit
