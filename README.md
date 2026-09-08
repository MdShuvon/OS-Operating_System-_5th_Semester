# Operating Systems Lab

This repository contains the Operating Systems lab programs I completed during my 5th semester.

## Programs

- `fcfs.cpp` - First Come, First Served scheduling
- `Shortestjobfirst.cpp` - non-preemptive Shortest Job First scheduling
- `ShortestjobfirstP.cpp` - preemptive Shortest Job First scheduling
- `bankersAlgo.cpp` - Banker's Algorithm for deadlock avoidance
- `priority_scheduling.cpp` - priority scheduling with waiting and turnaround time calculations
- `fcfs_example.cpp` - an additional FCFS implementation
- `bankers_algorithm_example.cpp` - an additional Banker's Algorithm implementation

## How to Compile and Run

Use a C++ compiler such as `g++`:

```bash
g++ -std=c++17 priority_scheduling.cpp -o priority_scheduling
./priority_scheduling
```

Replace the source and output names in the command to run another program.

## Topics Covered

- CPU scheduling algorithms
- Waiting time and turnaround time calculation
- Deadlock avoidance using the Banker's Algorithm