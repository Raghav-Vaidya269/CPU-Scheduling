# CPU Job Scheduling Simulator

Welcome to the **CPU Job Scheduling Simulator**! This is a modern, modular C++ application designed to simulate how an Operating System manages and schedules processes. It provides a hands-on way to understand classic scheduling algorithms and their impact on system performance.

---

##  Overview

In a multitasking environment, the CPU needs a strategy to decide which job to run next. This simulator emulates that process by taking a list of jobs (with arrival times, burst times, and priorities) and applying a scheduling algorithm to determine the execution order, waiting times, and turnaround times.

### Key Features
- **Multiple Input Modes**: Use built-in sample data for a quick demo or enter your own custom jobs manually.
- **Classic Algorithms**:
  - **FCFS (First-Come-First-Served)**: Simple and fair — first in, first out.
  - **Priority Scheduling**: Executes jobs based on urgency (lower priority values take precedence).
- **Real-time Simulation**: Features a smooth CLI progress bar to simulate the "work" being done by the CPU.
- **Detailed Analytics**: Comprehensive table showing ID, Arrival, Burst, Waiting, Turnaround, and Completion times.
- **Gantt Chart**: A visual timeline representing the sequence of job execution.

---

## Modular Architecture

One of the highlights of this project is its **Modular Design**. Instead of a single, cluttered source file, the project is organized into logical modules, making it professional, easy to debug, and highly extensible.

### File Structure & Responsibility

| File | Purpose |
| :--- | :--- |
| `Job.h` | **The Blueprint**: Defines the `Job` structure and acts as the bridge between all modules by declaring function prototypes. |
| `main.cpp` | **The Orchestrator**: Manages the user interface (menus) and handles the overall program flow. |
| `input.cpp` | **Data Entry**: Contains logic for manual job entry and sample data generation. |
| `algorithms.cpp` | **The Brain**: Implements the actual scheduling logic for FCFS and Priority algorithms. |
| `analytics.cpp` | **The Accountant**: Calculates metrics like Waiting Time and Turnaround Time, and prints the summary table. |
| `visuals.cpp` | **The Artist**: Handles CLI aesthetics, including the Gantt chart and the loading animation. |

### Why Modularity?
- **Separation of Concerns**: Each file does exactly one thing. If you want to add a "Shortest Job First" algorithm, you only need to touch `algorithms.cpp` and `Job.h`.
- **Reusability**: The `Job` struct and utility functions can be easily ported to other projects.
- **Readability**: Smaller files are easier to read and understand than a 1000-line monolithic file.

---

##  How to Build and Run

The project uses **CMake**, making it cross-platform and easy to compile.

1. **Create a build directory**:
   ```bash
   mkdir build && cd build
   ```
2. **Generate build files**:
   ```bash
   cmake ..
   ```
3. **Compile**:
   ```bash
   make
   ```
4. **Run the simulator**:
   ```bash
   ./JobScheduler
   ```

---

## Example Output

After running the simulation, you'll see a clean breakdown:

```text
--- Job Statistics ---
ID   Arrival   Burst     Wait     Turnaround     Completion     
1    0         5         0        5              5              
2    1         3         4        7              8              
...

Average Waiting Time: 2.25
Average Turnaround Time: 6.50

--- Gantt Chart ---
| J1 | J2 | J3 | J4 |
0    5    8    16   22
```

---
*Created with ❤️ by Team Job Scheduleras a demonstration of clean C++ architecture.*
