def print_frames(frames, capacity):
    temp = frames.copy()
    while len(temp) < capacity:
        temp.insert(0, "-")
    print("Frames:", temp)


def lru(pages, capacity):
    frames = []
    recent = {}
    faults = 0

    print("\n--- LRU ---")
    for i, p in enumerate(pages):
        if p in frames:
            print(f"{p} -> Hit", end=" | ")
        else:
            faults += 1
            if len(frames) < capacity:
                frames.append(p)
            else:
                lru_page = min(frames, key=lambda x: recent[x])
                frames.remove(lru_page)
                frames.append(p)
            print(f"{p} -> Miss", end=" | ")

        recent[p] = i
        print_frames(frames, capacity)

    print("Total Page Faults:", faults)


# 🔹 Input
pages = list(map(int, input("Enter page reference string: ").split()))
capacity = int(input("Enter number of frames: "))

lru(pages, capacity)
