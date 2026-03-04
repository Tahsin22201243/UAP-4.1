#include <iostream>
using namespace std;

int main() {
    int totalProcesses;

    cout << "Enter number of processes: ";
    cin >> totalProcesses;

    int processID[totalProcesses];
    int burstTime[totalProcesses];
    int priority[totalProcesses];
    int completionTime[totalProcesses];
    int waitingTime[totalProcesses];
    int temp;

    // Input Burst Time and Priority
    for (int i = 0; i < totalProcesses; i++) {
        processID[i] = i + 1;

        cout << "Enter Burst Time for Process " << processID[i] << ": ";
        cin >> burstTime[i];

        cout << "Enter Priority for Process " << processID[i] << ": ";
        cin >> priority[i];
    }

    // Sort processes according to priority (Ascending order)
    for (int i = 0; i < totalProcesses - 1; i++) {
        for (int j = i + 1; j < totalProcesses; j++) {

            if (priority[i] > priority[j]) {

                // Swap Priority
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                // Swap Burst Time
                temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;

                // Swap Process ID
                temp = processID[i];
                processID[i] = processID[j];
                processID[j] = temp;
            }
        }
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

    cout << "\nProcess\tPriority\tBurst Time\tCompletion Time\tWaiting Time\n";

    for (int i = 0; i < totalProcesses; i++) {
        cout << processID[i] << "\t"
             << priority[i] << "\t\t"
             << burstTime[i] << "\t\t"
             << completionTime[i] << "\t\t"
             << waitingTime[i] << endl;

        totalWaitingTime += waitingTime[i];
    }

    cout << "\nAverage Waiting Time: "
         << totalWaitingTime / totalProcesses << endl;

    return 0;
}
