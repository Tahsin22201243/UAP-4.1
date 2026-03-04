#include <iostream>
using namespace std;

int main() {

    int totalProcesses, timeQuantum;

    cout << "Enter number of processes: ";
    cin >> totalProcesses;

    cout << "Enter Time Quantum: ";
    cin >> timeQuantum;

    int processID[totalProcesses];
    int burstTime[totalProcesses];
    int remainingTime[totalProcesses];
    int completionTime[totalProcesses];
    int waitingTime[totalProcesses];

    // Input (Only Burst Time)
    for (int i = 0; i < totalProcesses; i++) {
        processID[i] = i + 1;

        cout << "Enter Burst Time for Process " << processID[i] << ": ";
        cin >> burstTime[i];

        remainingTime[i] = burstTime[i];
    }

    int currentTime = 0;
    int completed = 0;

    // Round Robin Logic
    while (completed < totalProcesses) {

        for (int i = 0; i < totalProcesses; i++) {

            if (remainingTime[i] > 0) {

                if (remainingTime[i] > timeQuantum) {
                    currentTime += timeQuantum;
                    remainingTime[i] -= timeQuantum;
                }
                else {
                    currentTime += remainingTime[i];
                    completionTime[i] = currentTime;

                    remainingTime[i] = 0;
                    completed++;
                }
            }
        }
    }

    // Calculate Waiting Time
    double totalWT = 0;

    for (int i = 0; i < totalProcesses; i++) {
        waitingTime[i] = completionTime[i] - burstTime[i];
        totalWT += waitingTime[i];
    }

    // Display
    cout << "\nPID\tBT\tCT\tWT\n";

    for (int i = 0; i < totalProcesses; i++) {
        cout << processID[i] << "\t"
             << burstTime[i] << "\t"
             << completionTime[i] << "\t"
             << waitingTime[i] << endl;
    }

    cout << "\nAverage Waiting Time: "
         << totalWT / totalProcesses << endl;

    return 0;
}
