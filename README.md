# Maze Solver

**Name:** Zainab Ghafoor  
**ID:** 008259427  
**GitHub repository link:** [https://github.com/zainabghafoor0/maze_solver.git](https://github.com/zainabghafoor0/maze_solver.git)

---

## Project Description

This project implements a Maze Solver using a **backtracking** strategy to find a path from a designated **start** cell to a **target** cell in a 2D grid. The maze is represented as a matrix where `1` denotes a **wall** and `0` denotes a **free path**. The algorithm explores candidate moves depth-first and **automatically backtracks** when it encounters dead ends, guaranteeing that all reachable routes are explored until a solution is found (or none exists).

---

## Collaboration & Sources

- Maze format and baseline requirements were provided in course materials.
- High-level backtracking pseudocode was adapted from the project PDF.
- I implemented, tested, and debugged the solution independently.

**Primary files I authored:**  
- `maze_solver.cpp` — Core solver implementation (I/O, search, visualization)  
- `maze0-1_input.txt` — Sample 13×15 maze input

---

## Implementation Details

### 1) MazeSolver Class
- **Loading & Validation:** Parses a text file into a `std::vector<std::vector<int>>` grid; validates dimensions and characters.  
- **Auto-Detection:** Identifies **start** and **target** cells based on markers or inferred rules.  
- **Search Engine:** Depth-first search with an explicit `std::stack<std::pair<int,int>>` to track the current path.  
- **Visualization:** Pretty prints the original maze and overlays the discovered path using markers.

### 2) Core Algorithm: Backtracking

