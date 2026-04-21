def cscan(requests, head, disk_size):
    requests.sort()
    left = [r for r in requests if r < head]
    right = [r for r in requests if r >= head]

    path = []
    distance = 0

    path.extend(right)
    path.append(disk_size - 1)
    path.append(0)
    path.extend(left)

    current = head
    for r in path:
        distance += abs(current - r)
        current = r

    print("C-SCAN Path:", [head] + path)
    print("Total Distance:", distance)


# Example
cscan([98,183,37,122,14,124,65,67], 53, 200)