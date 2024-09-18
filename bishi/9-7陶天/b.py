def solve():
    n = int(input())  
    s = [0] * (n + 1)  
    s = [0] + list(map(int, input().split()))
    for i in range(1, n + 1):
        s[i] += s[i - 1]

    tot = s[n] 
    res = float('inf') 

    for i in range(1, n - 1):
        s1 = s[i]
        l, r = i + 1, n - 1
        while l < r:
            mid = (l + r + 1) // 2
            if tot - s[mid] >= s[mid] - s[i]:
                l = mid
            else:
                r = mid - 1
        s2 = s[n] - s[l]
        s3 = s[l] - s[i]
        res = min(res, max(s1, s2, s3) - min(s1, s2, s3))
        if l + 1 < n:
            s2 = s[n] - s[l + 1]
            s3 = s[l + 1] - s[i]
            res = min(res, max(s1, s2, s3) - min(s1, s2, s3))
            

    print(res)

def main():
    t = int(input()) 
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
