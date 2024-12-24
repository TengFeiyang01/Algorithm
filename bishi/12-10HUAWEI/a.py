from math import *

def solve() -> None:
    n = int(input())
    k = int(input())
    res = []
    status = (1 << (n + 1)) - 1
    for i in range(n):
        nxt = bin(status).count("1") - 1
        c0 = nxt - 1
        for j in range(n, 0, -1):
            if (status & (1 << j)) == 0: continue
            t = (nxt - 1) * factorial(c0)
            if k > t:
                res.append(str(j))
                k -= t
                status ^= 1 << j
                break
            nxt -= 1
    print("".join(res))

if __name__ == '__main__':
    solve()