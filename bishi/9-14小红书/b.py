def solve():
    T = int(input()) 
    for _ in range(T):
        a, b, c, k = map(int, input().split()) 
        ans = 0 

        if k > a * b * c:
            print(0)
            continue

        for i in range(1, a + 1):
            if k % i != 0:
                continue
            for j in range(1, b + 1):
                if k % (i * j) != 0:
                    continue
                x = k // (i * j)
                if x <= c:
                    ans = max(ans, (a - i + 1) * (b - j + 1) * (c - x + 1))

        print(ans)  

if __name__ == '__main__':
    solve()
