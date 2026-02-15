# CPU Job Scheduling Simulator

## Project Overview
The **CPU Job Scheduling Simulator** is a console-based C++ application designed to demonstrate how Operating Systems manage process execution. It simulates core scheduling algorithms to order execution, minimize waiting times, and optimize system resource usage.

This project uses a **modular architecture**, separating logic into distinct files for input handling, algorithm processing, analytics, and visualization. It serves as an educational tool for understanding FCFS (First-Come-First-Served) and Priority Scheduling algorithms.

---

## Features
- **Supported Algorithms**:
  - **FCFS (First-Come-First-Served)**: Processes jobs in the order they arrive.
  - **Priority Scheduling (Non-preemptive)**: Executes jobs based on priority levels (lower integer = higher priority).
- **Flexible Input**:
  - **Sample Jobs**: Load pre-defined data for quick demonstration.
  - **Manual Input**: Enter custom job details (ID, Arrival Time, Burst Time, Priority).
- **Visualization**:
  - **Progress Bar**: Simulates CPU execution time with a CLI-based loading bar.
  - **Gantt Chart**: Visual timeline showing the sequence of job execution.
- **Detailed Analytics**:
  - Calculates and displays **Waiting Time**, **Turnaround Time**, and **Completion Time** for each job.
  - Computes global averages for performance analysis.

---

## Dependencies and Requirements
To build and run this project, you need:

1.  **C++ Compiler**: Supports C++11 or higher (GCC/MinGW recommended for Windows, Clang/GCC for Linux/macOS).
2.  **CMake**: Version 3.10 or higher for build automation.
3.  **Operating System**:
    - **Windows**: Fully supported (uses `windows.h` for timing/sleep simulation).
    - **Linux/WSL**: Source code logic is compatible, but platform-specific timing functions (like `Sleep`) may need adjustment to `usleep` or `std::this_thread::sleep_for`.

---

## Installation / Build Instructions

### Prerequisites (Windows)
Ensure you have **MinGW** and **CMake** installed and added to your system `PATH`.

### Build Steps
1.  **Clone or Download source code**.
2.  **Open a terminal** in the project root directory.
3.  **Create a build directory**:
    ```powershell
    mkdir build
    cd build
    ```
4.  **Generate Build Files (using MinGW)**:
    ```powershell
    cmake -G "MinGW Makefiles" ..
    ```
    *(Note: If `cmake ..` automatically finds MinGW, you can just use `cmake ..`)*
5.  **Compile the Project**:
    ```powershell
    cmake --build .
    ```
    This will generate an executable named `JobScheduler.exe` in the `build` directory.

---

## Usage
Run the simulator from the terminal:

```powershell
./JobScheduler.exe
```

### runtime Options
1.  **Select Input Method**:
    - `1`: Use built-in sample jobs.
    - `2`: Enter your own jobs (Start Time, Burst Time, Priority).
2.  **Select Algorithm**:
    - `1`: FCFS.
    - `2`: Priority Scheduling.
3.  **Simulation**:
    - Watch the progress bar simulate execution.
    - View the resulting **Analytics Table** and **Gantt Chart**.

---

## Sample Output

```text
--- CPU Job Scheduling Simulator ---
Created by Team 4 (Modular Architecture)

1. Use Sample Jobs
2. Enter Jobs Manually
3. Exit
Select input method: 1

1. FCFS (First-Come-First-Served)
2. Priority Scheduling (Non-preemptive)
Select algorithm: 1

Simulating scheduling...
Loading: 100%

--- Job Statistics ---
ID   Arrival   Burst     Wait     Turnaround     Completion
1    0         5         0        5              5
2    1         3         4        7              8
3    2         8         6        14             17
4    3         6         14       20             23

Average Waiting Time: 6.00
Average Turnaround Time: 11.50

--- Gantt Chart ---
| J1 | J2 | J3 | J4 |
0    5    8    16   23
```

---

## Project Structure

The project follows a modular design principle to ensure maintainability and readability:

- **`main.cpp`**: The entry point. Handles user menus, orchestrates the simulation flow, and calls respective modules.
- **`Job.h`**: Header file defining the `Job` structure (properties like ID, Arrival, Burst, Priority) and declaring all shared functions.
- **`input.cpp`**: Handles data ingestion, providing functions for both manual user input and hardcoded sample data.
- **`algorithms.cpp`**: Contains the core logic for `runFCFS` and `runPriorityScheduling`. Implements sorting and queue management.
- **`analytics.cpp`**: Calculates performance metrics (waiting time, turnaround time) and prints the statistical table.
- **`visuals.cpp`**: Manages CLI output formatting, including the Gantt chart drawing logic.

---

## Technical Notes
- **Threading & Timing**: The application currently uses `windows.h` and `Sleep()` for simulating execution delays on Windows systems. This replaces `std::this_thread::sleep_for` to ensure compatibility with specific MinGW thread models.
- **Data Structures**: `std::vector` is used extensively for dynamic job storage, allowing flexible input sizes.
- **Modular Build**: `CMakeLists.txt` defines the build process, compiling all source files (`algorithms.cpp`, `input.cpp`, etc.) into a single executable.

---

## Future Improvements / Extensions
- **Round Robin Scheduling**: Implement time quantum-based scheduling.
- **Preemptive Priority**: Allow higher priority jobs to interrupt running jobs.
- **File Input**: Load job data from a CSV or text file.
- **Cross-Platform Threading**: Refactor timing logic to use strictly standard C++11 `<thread>` and `<chrono>` where the compiler environment permits (e.g., using `pthreads` on MinGW or MSVC).
