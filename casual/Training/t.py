# D:\Algorithm\casual\Training\t.py 2024-09-06 by ytf
import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))


# 这个是最上面的
pri = []
not_prime = [False] * (100001)

# 这是使用线性筛法预处理[1, n]所有的质数
def pre(n):
    for i in range(2, n + 1):
        if not not_prime[i]: # not_prime[i] # 抄错啦 少了 [i]
            pri.append(i)
        for pri_j in pri:
            if i * pri_j > n:
                break
            not_prime[i * pri_j] = True
            if i % pri_j == 0:
                break


def solve() -> None:
    pre(100000)  # 这个漏掉啦 哼哼

    a = []  # a 初始化

    # 需要修改输入处理
    b = list(input().split())  # 这里 print(b) 试试
    for x in b:
        if x.isdigit(): # 对输入处理 python 内置函数 判断是否是数字 只处理数字
            a.append(int(x))

    ans = []
    # 这里是 a 不是ans
    for x in a:
        if not not_prime[x]:
            ans.append(x)
    print(*ans)


# 调用别忘记  自测输入 不需要导包
if __name__ == '__main__':
    solve()