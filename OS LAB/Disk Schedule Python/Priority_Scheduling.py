
n = int(input("Enter number of processes: "))

process = []
burst = []
priority = []

for i in range(n):
    process.append("P" + str(i+1))
    b = int(input(f"Enter Burst Time for P{i+1}: "))
    p = int(input(f"Enter Priority for P{i+1}: "))
    burst.append(b)
    priority.append(p)


combined = list(zip(priority, burst, process))
combined.sort()  

priority, burst, process = zip(*combined)

current_time = 0
total_waiting = 0

for i in range(n):
    total_waiting += current_time
    current_time += burst[i]

avg_waiting = total_waiting / n

print("\nProcess\tBurst\tPriority")
for i in range(n):
    print(process[i], "\t", burst[i], "\t", priority[i])

print("\nAverage Waiting Time =", avg_waiting)