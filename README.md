# Smart Exam Timetable Generator (SETG)

## Overview
This project solves the exam scheduling problem using graph coloring techniques. Each course is modeled as a node, and edges represent conflicts due to shared students.



## Objective
- Generate a conflict-free exam timetable  
- Minimize number of time slots  
- Compare different algorithmic approaches  



## Problem Modeling
- Nodes represent courses  
- Edges represent conflicts (common students)  
- Colors represent time slots  



## Algorithms Implemented

### Greedy Coloring
- Assigns the lowest available slot  
- Fast but not always optimal  
- Time Complexity: O(V²)  

### Backtracking (Exact)
- Guarantees optimal solution  
- Time Complexity: O(m^V)  

### DSATUR (Heuristic)
- Selects node with highest saturation  
- Near-optimal and efficient  
- Time Complexity: O(V²)  



## Sample Output

===== EXAM TIMETABLE =====

Course   ->   Time Slot
------------------------
C1       ->   Slot 0
C2       ->   Slot 1
C3       ->   Slot 1
C4       ->   Slot 0

Total Slots Used: 2  
Conflicts: 0  



## Project Structure
- src/ : Source code  
- docs/ : Report  
- tests/ : Input cases  



## How to Run
Compile:
g++ file.cpp -o run  

Run:
./run  


## Conclusion
Graph coloring provides an efficient approach to exam scheduling. DSATUR offers the best balance between optimality and performance.



## Team Members
- Krishna Ramesh (24BDS0420)  
- Makkineni Bhuvan (22BKT0068)
