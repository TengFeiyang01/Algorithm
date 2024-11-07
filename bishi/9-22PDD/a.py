import sys
from collections import *

def solve() -> None:
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        avg = sum(a) / n
        cnt = defaultdict(int)
        ans = 0
        s = avg * 2
        for x in a:
            ans += cnt[s - x]
            cnt[x] += 1
        print(ans)
        
    
if __name__ == '__main__':
    solve()