n = int(input("Enter number of processes: "))

process = []
burst = []

for i in range(n):
    process.append("P" + str(i + 1))
    b = int(input(f"Enter Burst Time for P{i+1}: "))
    burst.append(b)

waiting = [0] * n

# Calculate waiting time
for i in range(1, n):
    waiting[i] = waiting[i - 1] + burst[i - 1]

total_waiting = sum(waiting)
avg_waiting = total_waiting / n

print("\nProcess\tBurst\tWaiting")
for i in range(n):
    print(process[i], "\t", burst[i], "\t", waiting[i])

print("\nAverage Waiting Time =", avg_waiting)
