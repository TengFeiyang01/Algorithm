from math import factorial

def binomial_coefficient(n, k):
    """计算组合数 C(n, k)"""
    return factorial(n) // (factorial(k) * factorial(n - k))

def fuss_catalan_number(n, k):
    """计算给定 n 和 k 的 Fuss-Catalan 数"""
    return binomial_coefficient((k + 1) * n, n) // (k*n + 1)

# 示例：计算 n=3, k=2 的情况
n = 3
k = 4
num_sequences = fuss_catalan_number(n, k)
print(num_sequences)
