import sys
from collections import defaultdict

def main():
    input = sys.stdin.read
    data = input().split()

    n = int(data[0])
    hp = defaultdict(list)

    for i in range(1, n + 1):
        v = int(data[i])
        cnt = bin(v).count('1')
        hp[cnt].append(v)

    res = 0

    for nk, lst in hp.items():
        lst.sort()
        dp = {v: 1 for v in lst}

        for v in lst:
            z = dp[v]
            res = max(res, z)

            low = v & (-v)
            nv = v + low
            n1 = bin(nv).count('1')

            for i in range(30):
                if n1 >= nk:
                    break
                if (nv & (1 << i)) == 0:
                    nv |= (1 << i)
                    n1 += 1

            if nv in dp:
                dp[nv] = max(dp[nv], z + 1)

    print(res)

if __name__ == "__main__":
    main()