import sys
mod = 1_000_000_007
T = int(input())
for _ in range(T):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    s = 0
    ans = 0
    for x in a:
        s = max(x, s + x)
        ans = max(ans, s)
    tot = sum(a)
    print((tot - ans + ans * pow(2, k, mod)) %  mod)