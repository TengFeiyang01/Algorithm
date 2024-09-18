import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


def findTotalBeauty(arr, pairs):
    n = len(arr)
    st = set()
    cnt = [0] * (n + 1)
    for x, y in pairs:
        st.add(x)
        st.add(y)
        cnt[x] += 1
        cnt[y + 1] -= 1
    for i in range(1, n+1):
        cnt[i] += cnt[i - 1]
    
    a = [(arr[i], cnt[i], i) for i in range(n)]
    a.sort()
    ans = 0
    pre = 0
    i = 0
    while i < n:
        j = i
        cur = 0
        while j < n and a[j][0] == a[i][0]:
            if cnt[a[j][2]] == 0:
                ans += pre
            cur += a[j][1]
            j += 1
        pre += cur
        i = j

    print(ans)



def solve() -> None:
    a = ints()
    m = sint()
    b = [ints() for _ in range(m)]
    findTotalBeauty(a, b)

if __name__ == '__main__':
    solve()