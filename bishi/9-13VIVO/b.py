
n = int(input())
arr = []
for _ in range(n):
    r = list(map(int, input().split()))
    arr.append(r)

arr.sort(key=lambda x: -x[1])

def getDays():
    for i in range(1, n):
        if i + (i + 1) // 2 >= n:
            return i
    return n

x = getDays()
# print (x)

brr = []
for i in range(n):
    brr.append(i)

brr.sort(key=lambda p: (arr[p][0] + arr[p][1] * (x - 1)))
brr = brr[:x]

#print (brr)

brr.sort(key=lambda x: -arr[x][1])

res = 0
for (i, p) in enumerate(brr):
    res += arr[p][0] + arr[p][1] * i

print (res)
