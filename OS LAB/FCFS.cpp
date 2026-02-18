#include <iostream>
using namespace std;

int main() {
    int totalProcesses;
    cout << "Enter number of processes: ";
    cin >> totalProcesses;

    int processID[totalProcesses];
    int burstTime[totalProcesses];
    int completionTime[totalProcesses];
    int waitingTime[totalProcesses];

    // Input Burst Time
    for (int i = 0; i < totalProcesses; i++) {
        processID[i] = i + 1;
        cout << "Enter Burst Time for Process " << processID[i] << ": ";
        cin >> burstTime[i];
    }

    // First process
    waitingTime[0] = 0;
    completionTime[0] = burstTime[0];

    // Remaining processes
    for (int i = 1; i < totalProcesses; i++) {
        waitingTime[i] = completionTime[i - 1];
        completionTime[i] = waitingTime[i] + burstTime[i];
    }

    // Display results
    double totalWaitingTime = 0;

    cout << "\nProcess\tBurst Time\tCompletion Time\tWaiting Time\n";

    for (int i = 0; i < totalProcesses; i++) {
        cout << processID[i] << "\t"
             << burstTime[i] << "\t\t"
             << completionTime[i] << "\t\t"
             << waitingTime[i] << endl;

        totalWaitingTime += waitingTime[i];
    }

    cout << "\nAverage Waiting Time: "
         << totalWaitingTime / totalProcesses << endl;

    return 0;
}
