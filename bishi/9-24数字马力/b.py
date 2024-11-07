
def solve() -> None:
    n = int(input())
    a = list(map(int, input().split()))
    cnt = [2] * (n + 1)
    
    for i in range(n):
        if i + 2 < n:
            j, k = i + 1, i + 2
            if cnt[a[i]] and cnt[a[j]] and cnt[a[k]] == 2 and a[k] > max(a[i], a[j]):
                cnt[a[i]] -= 1
                cnt[a[j]] -= 1
                cnt[a[k]] -= 2
                a[i], a[j], a[k] = a[k], a[i], a[j]
                
        if i + 1 < n:
            j = i + 1
            if cnt[a[i]] and cnt[a[j]] and a[j] > a[i]:
                cnt[a[i]] -= 1
                cnt[a[j]] -= 1
                a[i], a[j] = a[j], a[i]
    print(*a)

if __name__ == '__main__':
    solve()