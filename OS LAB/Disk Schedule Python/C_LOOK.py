def clook(requests, head):
    requests.sort()
    left = [r for r in requests if r < head]
    right = [r for r in requests if r >= head]

    path = []
    distance = 0

    path.extend(right)
    path.extend(left)

    current = head
    for r in path:
        distance += abs(current - r)
        current = r

    print("C-LOOK Path:", [head] + path)
    print("Total Distance:", distance)


# Example
clook([98,183,37,122,14,124,65,67], 53)