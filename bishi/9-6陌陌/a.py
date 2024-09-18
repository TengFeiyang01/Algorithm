class Matrix:
    mod = int(1e9 + 7)

    def __init__(self, n, m=None):
        if m is None:
            m = n
        self.sorce = [[0] * m for _ in range(n)]
        if n == m: 
            for i in range(n):
                self.sorce[i][i] = 1

    def __mul__(self, b):
        n = len(self.sorce)
        m = len(b.sorce[0])
        res = Matrix(n, m)
        for i in range(n):
            for j in range(m):
                res.sorce[i][j] = 0
                for k in range(len(b.sorce)):
                    res.sorce[i][j] += self.sorce[i][k] * b.sorce[k][j] % self.mod
                res.sorce[i][j] %= self.mod
        return res

    def __imul__(self, b):
        self = self * b
        return self

    def __pow__(self, n):
        ans = Matrix(len(self.sorce))
        temp = self
        while n:
            if n & 1:
                ans *= temp
            n >>= 1
            temp *= temp
        return ans

    def __ipow__(self, n):
        self = self ** n
        return self

class Soultion:
    def solution(self, a, b, k):
        n = len(a)
        st = set()
        p = 0
        
        a = tuple(a)
        f = []
        while a not in st:
            st.add(a)
            f.append(a)
            p += 1
            na = [0] * n
            for i in range(n):
                na[i] = a[b[i]-1]
            a = tuple(na)
        k %= p
        result = list(f[k])
        print(result)
        return 1

def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    s = Soultion().solution(a, b, k)
    # mat = Matrix(n)
    # for i in range(n):
    #     for j in range(n):
    #         if j == b[i] - 1:
    #             mat.sorce[i][j] = 1
    #         else:
    #             mat.sorce[i][j] = 0

    # mat **= k

    # ans = [0] * n
    # for i in range(n):
    #     for j in range(n):
    #         ans[i] += mat.sorce[i][j] * a[j]
    #         ans[i] %= mat.mod

    # print(" ".join(map(str, ans)))


if __name__ == "__main__":
    solve()