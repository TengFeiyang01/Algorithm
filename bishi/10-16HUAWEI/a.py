import sys
from heapq import *

def main():
    import sys

    n = int(input())
    m = int(input())

    arr = list(map(int, input().split()))

    h = []
    for i, x in enumerate(arr, 1):
        if len(h) < n:
            heappush(h, (-i, x))
        else:
            pos, val = h[-1]
            if val >= x:
                heappop(h)
                heappush(h, (-i, x))
    mx = pos = 0
    for i, x in h:
        if x > mx:
            pos = -i - 1
            mx = x
        elif x == mx:
            pos = max(pos, -i - 1)
    print(pos)


if __name__ == "__main__":
    main()
