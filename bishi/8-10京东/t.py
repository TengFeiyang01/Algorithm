def solve():
    s = input()
    x, y = map(int, input().split())
    n = len(s)
    
    l = [False] * n
    r = [False] * n
    
    p = 0
    for i in range(n):
        d = int(s[i])
        p = p * 10 + d
        if p % x == 0:
            l[i] = True
        p %= x

    p = 0
    q = 1
    tot = 0
    for i in range(n-1, -1, -1):
        d = int(s[i])
        tot = d * q + tot
        if tot % y == 0:
            r[i] = True
        tot %= y
        q = q * 10 % y


    for i in range(1, n):
        if s[i] != '0' and l[i-1] and r[i]:
            print(s[:i], s[i:])
            return
    
    print("-1")

if __name__ == "__main__":
    solve()
