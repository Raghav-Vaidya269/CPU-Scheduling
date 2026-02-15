#include "Job.h"
#include <iostream>
#include <vector>
#include <windows.h>

int main() {
    std::cout << "--- CPU Job Scheduling Simulator ---\n";
    std::cout << "Created by Team 4 (Modular Architecture)\n\n";

    int choice;
    std::cout << "1. Use Sample Jobs\n";
    std::cout << "2. Enter Jobs Manually\n";
    std::cout << "3. Exit\n";
    std::cout << "Select input method: ";
    std::cin >> choice;

    std::vector<Job> jobs;
    if (choice == 1) {
        jobs = getSampleJobs();
    } else if (choice == 2) {
        jobs = getJobsFromUserInput();
    } else {
        return 0;
    }

    int algoChoice;
    std::cout << "\n1. FCFS (First-Come-First-Served)\n";
    std::cout << "2. Priority Scheduling (Non-preemptive)\n";
    std::cout << "Select algorithm: ";
    std::cin >> algoChoice;

    for (int i = 1; i <= 100; ++i) {
        std::cout << "Loading: " << i << "%\r";
        Sleep(10);
    }
    std::cout << "\nSimulation Complete!\n";

    if (algoChoice == 1) {
        runFCFS(jobs);
    } else if (algoChoice == 2) {
        runPriorityScheduling(jobs);
    } else {
        std::cout << "Invalid selection. Running FCFS by default.\n";
        runFCFS(jobs);
    }

    calculateAnalytics(jobs);
    printGanttChart(jobs);

    return 0;
}
