#include "Job.h"
#include <iostream>
#include <vector>


void printGanttChart(const std::vector<Job>& jobs) {
    if (jobs.empty()) return;

    std::cout << "\n--- Gantt Chart ---\n|";
    for (const auto& job : jobs) {
        std::cout << " J" << job.id << " |";
    }
    std::cout << "\n0";
    for (const auto& job : jobs) {
        if (job.completionTime < 10) std::cout << "    " << job.completionTime;
        else std::cout << "   " << job.completionTime;
    }
    std::cout << "\n";
}

void showProgressBar(int current, int total) {
    float progress = (float)current / total;
    int barWidth = 50;

    std::cout << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();
}
