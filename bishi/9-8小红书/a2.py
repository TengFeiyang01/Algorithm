n = int(input())
arr = list(map(int, input().split()))
arr.sort()
cnt = []
for i in range(n):
    cnt.append((i + 1) * (n - i))
cnt.sort()
print(sum(arr[i] * cnt[n - i - 1] for i in range(n)))