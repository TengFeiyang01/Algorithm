import sys

N = 100002
primes = []
st = [False] * N

def pre(n):
    for i in range(2, n + 1):
        if not st[i]:
            primes.append(i)
        for p in primes:
            if i * p > n:
                break
            st[i * p] = True
            if i % p == 0:
                break
            
MOD = 10 ** 9 + 7
            
def mul(A, B):
    return [[A[0][0] * B[0][0] + A[0][1] * B[1][0] % MOD,
             A[0][0] * B[0][1] + A[0][1] * B[1][1]] % MOD,
            [A[1][0] * B[0][0] + A[1][1] * B[1][0] % MOD,
             A[1][0] * B[0][1] + A[1][1] * B[1][1]] % MOD]

def mat_pow(A, n):
    result = [[1, 0], [0, 1]]
    base = A
    
    while n > 0:
        if n % 2 == 1:
            result = mul(result, base)
        base = mul(base, base)
        n //= 2
    
    return result

def get(x, y, n):
    if n == 1:
        return x
    elif n == 2:
        return y
    
    A = [[1, 1], [1, 0]]
    
    An_minus_2 = mat_pow(A, n - 2)
    
    Fn = An_minus_2[0][0] * y + An_minus_2[0][1] * x
    return Fn % MOD

pre(N-1)

def solve() -> None:
    a, b, n = map(int, input().split())
    ans = 1
    for cur in primes:
        if cur > a and cur > b:
            break
        x, y = 0, 0
        t = a
        p = cur
        while t:
            t //= p
            x += t
        t = b
        p = cur
        while t:
            t //= p
            y += t
        ans *= get(x, y, n) + 1
        ans %= MOD
    print(ans)
    
    
    
    
if __name__ == '__main__':
    solve()