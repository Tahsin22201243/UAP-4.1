
n = int(input("Enter number of processes: "))

process = ["P" + str(i+1) for i in range(n)]
burst = [int(input(f"Enter Burst Time for {process[i]}: ")) for i in range(n)]
remaining = burst.copy()
waiting = [0] * n

quantum = int(input("Enter Time Quantum: "))

time = 0
while any(remaining):  
    for i in range(n):
        if remaining[i] > 0:
            if remaining[i] > quantum:
                time += quantum
                remaining[i] -= quantum
            else:
                time += remaining[i]
                waiting[i] = time - burst[i]
                remaining[i] = 0

print("\nProcess\tBurst")
for i in range(n):
    print(f"{process[i]}\t{burst[i]}")

avg_waiting = sum(waiting) / n
print("\nAverage Waiting Time =", avg_waiting)