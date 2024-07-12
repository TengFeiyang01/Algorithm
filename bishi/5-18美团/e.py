mod = 10**9+7

n = int(input())
a = ['']
st = [[0]*26 for _ in range(n+1)]
p = [(10**6, 0)] * 26

for i in range(1, n+1):
    a.append(input())
    for ch in a[i]:
        st[i][ord(ch) - ord('a')] += 1
    for j in range(26):
        if st[i][j] != 0:
            if ((2 * len(a[i]) - st[i][j]) / st[i][j]) < p[j][0]:
                p[j] = ((2 * len(a[i]) - st[i][j]) / st[i][j], i)

q = int(input())

for _ in range(q):
    s = input()
    res = 0
    for ch in s:
        cnt = ord(ch) - ord('a')
        c = p[cnt][1]
        if c == 0:
            res = -1
            break
        res = (res + (2 * len(a[c]) - st[c][cnt]) * pow(st[c][cnt], mod - 2, mod)) % mod
    print(res)
