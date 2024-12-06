import sys

from heapq import heapify, heappop, heappush
def main():
    n = int(input())
    m = int(input())
    tasks = list(map(int, input().split()))

    h = []

    for i, cur in enumerate(tasks):
        if len(h) < n:
            heappush(h, (-cur, -i))
        else:
            pre, pos = h[0]
            if cur <= -pre:
                heappop(h)
                heappush(h, (-cur, -i))
    mx = res = -1
    for (t, pos) in h:
        t = -t
        if t > mx or (t == mx and -pos > res):
            mx = t
            res = -pos

    print(res)

if __name__ == "__main__":
    main()