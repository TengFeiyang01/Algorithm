### 第一题

#### 题意

一个更衣室有多个储物柜，供人们存放和取回物品。

一个自动化的储物柜系统被引入更衣室，当客户访问时，系统的工作方式如下：

- 如果客户没有被分配储物柜，系统分配给他们一个具有最小可用编号的储物柜。
- 如果客户已经有分配的储物柜，系统打开并释放储物柜。之后，该储物柜可以重新分配给其他客户。

锁柜从1开始编号。一天开始时，所有锁柜都是空的。系统被访问了N次。问最后一次被分配给某个客户的是哪个储物柜？

> 输入：一个包含N个客户名字的字符串数组 clients，表示客户访问更衣室的顺序。$3 \le N \le 300$
>
> 输出：返回最后一个被分配的储物柜的编号。 数组 clients 中的每个字符串由最多 20 个英文字母组成（'A'-'Z'，'a'-'z'）。

#### 样例

1. 对于 clients = ["Alice", "Eve", "Bob", "Eve", "Carl", "Alice"]，发生以下事件：

   - 储物柜 1 被分配给 Alice；
   - 储物柜 2 被分配给 Eve；
   - 储物柜 3 被分配给 Bob；
   - Eve 释放了储物柜 2；
   - 储物柜 2 被分配给 Carl；
   - Alice 释放了储物柜 1；

   最后一个储物柜被分配给 Carl，所以函数应该返回 2。

2. 对于 clients = ["Alice", "Bob", "Bobby"]，函数应该返回 3。

3. 对于 clients = ["Bob", "bob", "BoB", "bob", "BOB"]，函数应该返回 2，因为大小写字母应区分对待。

4. 对于 clients = ["Alice", "Alice", "Bob", "Alice"]，函数应该返回 2。

#### 思路

使用最小堆维护所有空闲的柜子编号，每当有人时，取出最小的分配，当有人释放柜子时，入堆即可，每次分配后记录答案。

#### 代码

```python
from collections import *
from heapq import *

def solution(clients):
    h = []
    n = len(clients)
    # 可用的柜子编号 
    for i in range(n):
        heappush(h, i + 1)

    d = Counter()  # 记录当前用户是否有柜子
    p = Counter()  # 记录当前用户柜子编号
    ans = -1
    for u in clients:
        if d[u] == 0:
            ans = heappop(h)
            p[u] = ans
        else:
            heappush(h, p[u])
            del p[u]
        d[u] ^= 1
    print(ans)
```

### 第二题

#### 题意

有 N 次连续的测量（编号从 0 到 N-1），在第 K 次测量中，设备记录了心率 ($heartRate[K]$) 和活动水平 ($activityLevel[K]$)（可能的活动水平是 "Low"、"Normal" 或 "High"）。

求在连续的同一活动水平期间，心率最高值和最低值之间的最大差异是多少？

> 输入：一个包含整数的数组 heartRate，表示每次测量的心率。一个包含字符串的数组 activityLevel，表示每次测量的活动水平。

> 输出：返回在同一活动水平期间，心率最高值和最低值之间的最大差异。

#### 样例

1.  `heartRate` = [60, 100, 90, 80] 和 `activityLevel` = ["Low", "High", "High", "High"]。在 "Low" 活动水平期间只有一次测量，所以差异是 0。在 "High" 活动水平期间有三次测量，心率最高值和最低值之间的差异为 20。函数应返回 20。
2.  `heartRate` = [82, 120, 78, 61] 和 `activityLevel` = ["Normal", "High", "Normal", "Low"]。所有相同水平的活动周期长度都是 1，所以函数应返回 0。
3.  `heartRate` = [100, 87, 90, 90, 125] 和 `activityLevel` = ["Normal", "Normal", "Normal", "High", "Low"]，函数应返回 13。

#### 思路

双指针分组循环，每一组内的计算最大最小值，然后更新答案即可。

#### 代码

```python
def solution(heartRate, activityLevel):
    n = len(heartRate)
    ans = 0
    i = 0
    while i < n:
        j = i
        mx, mn = heartRate[i], heartRate[i]
        # 找连续的相同水平的记录
        while j < n and activityLevel[j] == activityLevel[i]:
            mx = max(mx, heartRate[j])
            mn = min(mn, heartRate[j])
            j += 1
        ans = max(ans, mx - mn)
        i = j
    print(ans)
```

