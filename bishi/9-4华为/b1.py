import sys
from collections import Counter

def solve():
    n, m, k, l = map(int, sys.stdin.readline().split())

    edges = []
    connected_to_k = set()

    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        if a == k or b == k:
            connected_to_k.add(a)
            connected_to_k.add(b)
        edges.append((a, b))

    counter = Counter()
    for a, b in edges:
        if b in connected_to_k and a not in connected_to_k:
            counter[a] += 1
        if a in connected_to_k and b not in connected_to_k:
            counter[b] += 1

    sorted_list = sorted((-count, node) for node, count in counter.items())

    result = []
    for i in range(l):
        if i < len(sorted_list):
            result.append(sorted_list[i][1])
        else:
            result.append(0)

    print(" ".join(map(str, result)))

if __name__ == "__main__":
    solve()
