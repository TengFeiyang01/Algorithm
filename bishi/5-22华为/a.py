
def solve():
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    n, m = len(a), len(b)
    len_max = 0
    start = 0
    
    for i in range(n):
        for j in range(m):
            k = 0
            while i + k < n and j + k < m and a[i + k] == b[j + k]:
                k += 1
            if k > len_max:
                len_max = k
                start = i
    
    if len_max == 0:
        print("-1")
        return

    print(" ".join(map(str, a[start:start + len_max])))

if __name__ == "__main__":
    solve()
