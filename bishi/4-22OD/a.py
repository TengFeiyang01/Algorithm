from collections import Counter

m, n, x = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

mx = 0  
cnt = Counter()

a = list(zip(a, b, c))

for i in range(m):
    if a[i][1] > x:
        continue

    k = min(c[i], n)
    if a[i][0] * k > mx:
        cnt.clear()
        cnt[i] = k
        mx = a[i][0] * k

    for j in range(i + 1, m):
        if a[i][1] + a[j][1] > x:
            continue

        cnti, cntj = a[i][2], a[j][2]
        if a[i][0] > a[j][0]:
            cnti = min(cnti, n)
            cntj = min(cntj, n - cnti)
        else:
            cntj = min(cntj, n)
            cnti = min(cnti, n - cntj)

        if a[i][0] * cnti + a[j][0] * cntj > mx:
            cnt = Counter()
            cnt[i] = cnti
            cnt[j] = cntj
            mx = a[i][0] * cnti + a[j][0] * cntj

res = [0] * m
for i in range(m):
    if i in cnt:
        res[i] = cnt[i]
print(*res)