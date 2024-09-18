### 题目1

题意：给你 $x, y, k$ 三个正整数，每次可以选择以下操作之一

- $x = x - 1$
- $x = x / k$ 当且仅当 $x \% k == 0 $ 

问你将 $x$ 变为 $y$ 的最小操作次数。

> 输入：三个正整数，$1 \le x, y, k \le 10^9$ 
>
> 输出：一行一个正整数，表示最小操作次数

样例

> 输入：
>
> 10 4 5
>
> 输出：
>
> 2

#### 思路

贪心，若 $x \% k != 0$ ，将 $x$ 减少到能整除为止，只到不能整除且大于等于 $y$ ，然后操作1即可。

#### 代码

```python
def solve() -> None:
    n, m, k = mint()
    if k == 1:
        print(m - n)
        return
    ans = 0
    
    while n != m:
        if n // k >= m:
            ans += n % k
            n //= k
        else:
            n -= 1
        ans += 1
    print(ans)    

if __name__ == '__main__':
    solve()
```

### 题目2

#### 题意

小O有一个字符串 $s$，她希望重新排列这个字符串，并改变字符的大小写，使得新的字符串包含尽可能多的字符串 $a$ 或者字符串 $b$ 。请问小O最多能包含多少个子串 $a$ 和 $b$ ，
如果字符串 $t$ 可以通过从字符串 $s$ 的开头删除若干(可能为零或全部)字符以及字符串 $s$ 的结尾删除若干(可能为零或全部)字符得到，则字符串 $t$ 是字符串 $s$ 的子串。

> 输入：三行三个字符串，s, a, b 其中 a和b开头均为大写，其余均为小写
>
> 输出：包含的子串个数

样例

> 输入：
>
> abcdefg
> Abc
> Fge
>
> 输出：
> 2

#### 思路

由于 $a$ 和 $b$ 的首字母大写，所有不存在重叠，那么考虑贪心，枚举有多少个 $a$ ,然后计算剩下的字符能组成多少个 $b$ ，取最大值即可

#### 代码

```python
def solve() -> None:
    s = input()
    a = input()
    b = input()
    s = [x.lower() for x in s]
    a = [x.lower() for x in a]
    b = [x.lower() for x in b]
    cnts = Counter(s)
    cnta = Counter(a)
    cntb = Counter(b)
    ans = 0
    for i in range(len(s)+1):
        ok = True
        for k, v in cnta.items():
            if cnts[k] < i * v:
                ok = False
        if ok:
            now = len(s)
            for k, v in cntb.items():
                now = min(now, (cnts[k] - i * cnta[k]) // v)
            ans = max(ans, i + now)
    print(ans)

if __name__ == '__main__':
    solve()
```

### 题目3

#### 题意

给你一颗树，包含 $n$ 个节点和 $n-1$ 条边，你可以在树中选两个节点进行连无向边，要求连边后的无向图是二分图，问你能连接的最多的边的个数。

> 输入：一行一个整数 n, 接下来 n-1 行输入树的边
>
> 输出：能增加的最多的边的条数

样例

> 输入：
>
> 4
> 1 2
> 2 3
> 3 4
>
> 输出：
>
> 2

#### 思路

二分图染色，将节点分为两个集合，那么两个集合的点相互连边，这样可以保证结果仍是二分图。假设两个集合个数为 $x, y=n-x$ , 那么答案为 $x*y-(n-1)$ 

#### 代码

```python
def solve() -> None:
    n = sint()
    adj = [[] for _ in range(n)]
    for i in range(n - 1):
        x, y = mint()
        adj[x - 1].append(y - 1)
        adj[y - 1].append(x - 1)
    m = 0
    def dfs(u, fa, c):
        nonlocal m
        if not c:
            m += 1
        for v in adj[u]:
            if v != fa:
                dfs(v, u, not c)
    dfs(0, -1, False)
    print(m * (n - m) - (n - 1))
    

if __name__ == '__main__':
    solve()
```

