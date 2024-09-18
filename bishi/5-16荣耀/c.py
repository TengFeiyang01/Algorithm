import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import inf
from collections import*


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def solve() -> None:
    songs = []
    cnt = defaultdict(int)
    t = defaultdict(str)
    preB, preP = None, None
    while True:
        try:
            ops = list(input().split())
            op, name, style = None, None, None
            if ops[0] == 'I':
                op, name, style = ops[0], ops[1], ops[2]
                songs.append(name)
                cnt[name] = 0
                t[name] = style
            elif ops[0] == 'P':
                op, name = ops[0], ops[1]
                if preP == t[name]:
                    for song in songs:
                        if song != name and t[name] == t[song]:
                            cnt[song] += 1
                cnt[name] += 3
                preP = t[ops[1]]
            else:
                op, name = ops[0], ops[1]
                cnt[name] -= 2
                if preB == t[name]:
                    for song in songs:
                        if song != name and t[name] == t[song]:
                            cnt[song] -= 1
                cnt[name] -= 2
                preB = t[ops[1]]
            
        except:
            break
    a = list(sorted(cnt.items(), key=lambda x:(-x[1], x[0])))
    for name, _ in a:
        print(name, t[name])
    
    
    
if __name__ == '__main__':
    solve()