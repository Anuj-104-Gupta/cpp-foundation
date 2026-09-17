#include<iostream>
#include<vector>
#include<algorithm>
#include"numeric"
#include"iterator"

using namespace std;

struct Process {
    int pid;
    int priority; // 1 to 10
    int memoryMB;
};

void printProcesses(const vector& procs) {
    for (const auto& p : procs) {
        cout << "PID: " << p.pid
             << " | Priority: " << p.priority
             << " | Memory: " << p.memoryMB << " MB\n";
    }
}

int main() {
    vector procs = {
        {101, 3, 256},
        {102, 9, 640},
        {103, 5, 128},
        {104, 9, 512},
        {105, 1, 32}
    };

    cout << "=== Initial Processes ===\n";
    printProcesses(procs);

    // 1. Sort descending by priority (higher priority first)
    sort(procs.begin(), procs.end(), [](const Process& a, const Process& b) {
        if (a.priority == b.priority) {
            return a.memoryMB < b.memoryMB;
        }
        return a.priority > b.priority;
    });

    cout << "\n=== After std::sort (Descending Priority) ===\n";
    printProcesses(procs);

    // 2. Find first process with memoryMB > 500
    auto heavyProcIt = find_if(procs.begin(), procs.end(), [](const Process& p) {
        return p.memoryMB > 500;
    });

    cout << "\n=== std::find_if (Memory > 500 MB) ===\n";
    if (heavyProcIt != procs.end()) {
        cout << "Found Heavy Process -> PID: " << heavyProcIt->pid
             << ", Mem: " << heavyProcIt->memoryMB << " MB\n";
    } else {
        cout << "No process found exceeding 500 MB.\n";
    }

    // 3. Count processes with priority >= 8
    int highPriorityCount = count_if(procs.begin(), procs.end(), [](const Process& p) {
        return p.priority >= 8;
    });

    cout << "\n=== std::count_if (Priority >= 8) ===\n";
    cout << "Number of high-priority processes: " << highPriorityCount << '\n';

    // 4. Extract all PIDs using std::transform
    vector pids;
    pids.reserve(procs.size());

    transform(procs.begin(), procs.end(), back_inserter(pids), [](const Process& p) {
        return p.pid;
    });

    cout << "\n=== std::transform (Extracted PIDs) ===\n";
    for (int id : pids) {
        cout << id << ' ';
    }
    cout << '\n';

    return 0;
}
