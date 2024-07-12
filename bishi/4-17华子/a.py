
def solve() -> None:
    n = int(input())
    stk = [None] * 100
    tp = 0
    s = list(input().split())
    for i in range(n):
        c = s[i]
        if tp == 0:
            tp += 1
            stk[tp] = c
        else:
            if tp >= 2 and stk[tp - 1] == stk[tp] and stk[tp] == c:
                tp -= 2
            else:
                tp += 1
                stk[tp] = c
    if tp == 0:
        print(0)
    else:
        print(*stk[1:tp+1])

if __name__ == '__main__':
    solve()