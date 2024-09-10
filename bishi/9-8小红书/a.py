import sys

def main():
    n = int(input())
    a = list(map(int, input().split()))
    

    cnt = [0] * n
    for i in range(n):
        cnt[i] = (i + 1) * (n - i)

    cnt.sort()
    a.sort()

    ans = 0
    for i in range(n):
        ans += cnt[i] * a[n - 1 - i]

    print(ans)

if __name__ == "__main__":
    main()