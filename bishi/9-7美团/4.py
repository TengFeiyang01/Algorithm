import sys
from sortedcontainers import SortedDict

def main():
    
    q = int(input())
    
    hp = SortedDict()
    
    for _ in range(q):
        x, s = map(int, input().split())
        y = x + s - 1

        ent = hp.bisect_right(x)
        if ent > 0:
            ent -= 1
            key = hp.keys()[ent]
            r = hp[key]
            if r >= x:
                x = key
                y = r + s
                del hp[key]

        while True:
            e2_index = hp.bisect_right(x)
            if e2_index >= len(hp):
                hp[x] = y
                break
            else:
                e2_key = hp.keys()[e2_index]
                e2_value = hp[e2_key]
                if e2_key > y:
                    hp[x] = y
                    break
                elif e2_value <= y:
                    y += (e2_value - e2_key + 1)
                    del hp[e2_key]
                elif e2_value > y:
                    y = e2_value + (y - e2_key + 1)
                    del hp[e2_key]

        print(y)

if __name__ == "__main__":
    main()
