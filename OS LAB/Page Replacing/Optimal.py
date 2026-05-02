def print_frames(frames, capacity):
    temp = frames.copy()
    while len(temp) < capacity:
        temp.insert(0, '-')
    print("Frames:", temp)


def optimal(pages, capacity):
    frames = []
    faults = 0

    print("\n--- Optimal ---")
    for i, p in enumerate(pages):
        if p in frames:
            print(f"{p} -> Hit", end=" | ")
        else:
            faults += 1
            if len(frames) < capacity:
                frames.append(p)
            else:
                future = pages[i+1:]
                farthest = -1
                replace = None

                for f in frames:
                    if f not in future:
                        replace = f
                        break
                    else:
                        idx = future.index(f)
                        if idx > farthest:
                            farthest = idx
                            replace = f

                frames.remove(replace)
                frames.append(p)

            print(f"{p} -> Miss", end=" | ")

        print_frames(frames, capacity)

    print("Total Page Faults:", faults)


# 🔹 Input
pages = list(map(int, input("Enter page reference string: ").split()))
capacity = int(input("Enter number of frames: "))

optimal(pages, capacity)