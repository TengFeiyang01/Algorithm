# D:\Algorithm\casual\Training\t.py 2024-09-06 by ytf
import sys

sys.setrecursionlimit(100000)

input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
from typing import *
from datetime import datetime

class Solution:
    def __init__(self):
        self.trades = []
        self.base_date = None
        self.interval = []

    def add_trade(self, future_trade: List):
        stock, date, price = future_trade
        self.trades.append((stock, date, float(price)))

    def convert_dates_to_days(self):
        dates = [datetime.strptime(trade[1], "%m/%d/%Y") for trade in self.trades]
        self.base_date = min(dates)
        
        for i in range(len(self.trades)):
            stock, date_str, price = self.trades[i]
            current_date = datetime.strptime(date_str, "%m/%d/%Y")
            days_since_start = (current_date - self.base_date).days
            self.trades[i] = (stock, days_since_start, price)
            
    def run(self):
        self.convert_dates_to_days()
        # 按天数排序交易信息
        print(self.trades)
        self.trades.sort(key=lambda x: x[1])
        d = defaultdict(list)
        mx = 0
        for x, t, p in self.trades:
            d[x].append((t, p))
            mx = max(mx, t)
        for v in d.values():
            for i in range(1, len(v)):
                x = v[i-1]
                y = v[i]
                self.interval.append((x[0], y[0], x[1], y[1]))
        self.interval.sort()
        n = len(self.interval)
        a = self.interval
        dp = [1000] * (n + 1)
        a.sort(key=lambda x:x[1])
        for i in range(1, n+1):
            st, ed, p1, p2 = a[i-1]
            for j in range(i-1, -1, -1):
                if j == 0 or a[j - 1][1] <= st:
                    dp[i] = max(dp[i], dp[j] / p1 * p2)
            dp[i] = max(dp[i], dp[i - 1])
        
        return round(max(dp)-1000 )      


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
