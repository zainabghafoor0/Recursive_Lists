Name: Zainab Ghafoor
ID: 008259427
GitHub repository link: [https://github.com/zainabghafoor0/Recursive_Lists.git
]

Project Description

This project implements a recursive list toolkit (à la Lisp) in C++ along with a suite of classic list-processing functions written purely with recursion—no loops or mutation.
Using the provided ADT (car, cdr, cons, is_atom, is_null, eq, read_list, write_list), the solution adds higher-level operations like flat, total_reverse, shape, set operations, deep equality, and more. The code compiles on a standard C++17 toolchain and runs from the command line, reading lists in the assignment’s S-expression style (atoms are 1–8 letters; () is the empty list).

Collaboration & Sources

Starter code & ADT: Course-provided files (reclists.*, parser.cpp, lex.*) and input format specification.

Design constraints: From the assignment—recursion only (no for/while/do), use of ADT ops and if/else permitted, I/O handled by provided code.

Work: All functions in solutions.cpp/.hpp implemented and tested by me. No external libraries or code used.

Implementation Details

Language & Build

C++17, standard library only.

Build:

g++ -std=c++17 -Wall -Wextra -O2 \
  main.cpp reclists.cpp parser.cpp lex.cpp solutions.cpp \
  -o recursive_lists


(If main.cpp uses std::numeric_limits, include <limits>.)

Repo Structure

Recursive_Lists/
├── main.cpp                 # minimal driver (you can extend for tests)
├── solutions.hpp            # prototypes (edited)
├── solutions.cpp            # implementations (edited)
├── reclists.hpp / reclists.cpp   # ADT (provided; do not modify)
├── parser.cpp               # input parsing (provided)
├── lex.hpp / lex.cpp        # tokenizer (provided)
└── sampleInputForRecLists.txt     # sample cases (comments + labels)


Implemented Functions (recursion-only)

Helpers: append(p,q), member(a,q) (deep atom membership), member_deep(x,q) (structural), pairs_cons.

Core:

is_lat(p) — top-level list of atoms

member(a,q) — atom appears anywhere (deep)

last(p) — last element (non-empty list)

list_pair(p,q) — zip atom lists → ((p1 q1) …)

firsts(p) — car of each sublist

flat(p) — deep flatten to one top-level atom list

two_the_same(p,q) — share ≥1 atom (deep)

equal(p,q) — full structural equality

total_reverse(p) — reverse at all levels

shape(p) — atoms → (), preserve parentheses only

intersection(p,q) — set intersection (distinct atoms)

list_union(p,q) — set union (distinct atoms, no dups)

substitute(old,new,p) — deep atom-wise replace

remove_all(p,a) — remove a from a flat atom list

subset(p,q) — every element of p (atom or sublist) occurs in q by equal

(Extra credit) permute(p) — all permutations of a flat atom list

All functions adhere to the assignment constraints: no loops, only ADT ops, recursion, and if/else.

How to Run (basic)

./recursive_lists
