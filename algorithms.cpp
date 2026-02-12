#include "Job.h"
#include <algorithm>
#include <queue>
#include <vector>

void runFCFS(std::vector<Job>& jobs) {
    // on basis of arrival time
    std::sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    for (auto& job : jobs) {
        if (currentTime < job.arrivalTime) {
            currentTime = job.arrivalTime;
        }
        job.waitingTime = currentTime - job.arrivalTime;
        currentTime += job.burstTime;
        job.completionTime = currentTime;
        job.turnaroundTime = job.completionTime - job.arrivalTime;
    }
}

struct PriorityCompare {
    bool operator()(const Job* a, const Job* b) {
        // Lower value = higher priority
        if (a->priority == b->priority) {
            return a->arrivalTime > b->arrivalTime;
        }
        return a->priority > b->priority;
    }
};

void runPriorityScheduling(std::vector<Job>& jobs) {
    int n = jobs.size();
    std::vector<Job> result;
    std::priority_queue<Job*, std::vector<Job*>, PriorityCompare> pq;
    
    //  copy to avoid messing up indices
    std::vector<Job> temp = jobs;
    std::sort(temp.begin(), temp.end(), [](const Job& a, const Job& b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;
    int completed = 0;
    int i = 0;

    while (completed < n) {
        // adding all jobs that have arrived at or before current time
        while (i < n && temp[i].arrivalTime <= currentTime) {
            pq.push(&temp[i]);
            i++;
        }

        if (pq.empty()) {
            if (i < n) {
                currentTime = temp[i].arrivalTime;
                continue;
            } else {
                break;
            }
        }

        Job* currentJob = pq.top();
        pq.pop();

        currentJob->waitingTime = currentTime - currentJob->arrivalTime;
        currentTime += currentJob->burstTime;
        currentJob->completionTime = currentTime;
        currentJob->turnaroundTime = currentJob->completionTime - currentJob->arrivalTime;
        
        // finding original job and update it
        for(auto& original : jobs) {
            if(original.id == currentJob->id) {
                original = *currentJob;
                break;
            }
        }
        completed++;
    }
}
