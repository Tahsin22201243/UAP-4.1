def scan(requests, head, disk_size, direction):
    requests.sort()
    left = [r for r in requests if r < head]
    right = [r for r in requests if r >= head]

    path = []
    distance = 0

    if direction == "left":
        left.reverse()
        path.extend(left)
        path.append(0)
        path.extend(right)
    else:
        path.extend(right)
        path.append(disk_size - 1)
        left.reverse()
        path.extend(left)

    current = head
    for r in path:
        distance += abs(current - r)
        current = r

    print("SCAN Path:", [head] + path)
    print("Total Distance:", distance)


# Example
scan([98,183,37,122,14,124,65,67], 53, 200, "right")