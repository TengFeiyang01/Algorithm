import sys
import heapq
import itertools
from heapq import heapify, heappop, heappush
from functools import lru_cache
from math import *
from collections import *


input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))

# 贪心思路：

#   将区间按右端点的大小进行排序（选择右端点是为了让这个点尽量包含在更多的区间内），第一个点选择第一个区间的右端点，之后的遍历中比较当前区间的左端点是否比当前所选的点小，如果小的话当前点可以包含在当前区间内，如果大的话就以当前区间的右端点为新点，并将所需区间的数加一，最后输出所需区间的数。

# 证明：
#   假设最优解为 ans 个不相交区间，以上述贪心思路选出来的区间为 cnt 个。即证明 ans = cnt，等价于 ans >= cnt && ans <= cnt
#   首先，以上述贪心思路选择出的 cnt 个区间，是一组可行方案。其覆盖了所有区间，满足题目要求。且 ans 表示的是所有可行方案的最大值，那么 ans >= cnt 成立
#   证明 ans <= cnt 时，可以采用反证法。假设 ans > cnt，则说明最多有 ans 个两两不交的区间，则至少需要 ans 个点才能将这些区间全部覆盖，然而实际上只需要 cnt 个点就能覆盖全部区间，且 cnt < ans。则矛盾，故 ans <= cnt 成立
#   时间复杂度：O(nlogn)


# 将工作按照结束时间排序
# 我们可以分类讨论，求出按照结束时间排序后的前 i 个工作的最大报酬：
#   不选第 i 个工作，那么最大报酬等于前 i-1 个工作的最大报酬（转换成了一个规模更小的子问题）；
#   选第 i 个工作，由于工作时间不能重叠，设 j 是最大的满足 endTime[j]≤startTime[i] 的 j，那么最大报酬等于前 j 个工作的最大报酬加上 weight[i]（同样转换成了一个规模更小的子问题）；
# 这两种决策取最大值。
# 注意，由于按照结束时间排序，前 j 个工作中的任意一个都不会与第 i 个工作的时间重叠。

"""
上述思路是一个标准的关于递推的描述，定义 f[i] 表示按照结束时间排序后的前 i 个工作的最大报酬，用「选或不选」分类讨论：
    不选第 i 个工作：
        f[i]=f[i-1]；
    选第 i 个工作：
    f[i]=f[j]+weight[i]，其中 j 是最大的满足 endTime[j]≤startTime[i] 的 j，不存在时为 -1。
    两者取最大值，即
        f[i]=max(f[i-1],f[j]+weight[i])
    由于 i=0 时会产生 -1，可以在 f 数组前面插入一个 0，与 f 有关的下标都 +1，即
        f[i+1]=max(f[i],f[j+1]+weight[i])
    初始项 f[0]=0，答案为 f[n]。
    代码实现时，由于结束时间是有序的，j 可以用二分查找计算出来
"""
# [(1, 3, 50), (2, 4, 10)]
from bisect import bisect_right
def getw(intervals) -> int:
    for i in range(len(intervals)):
        intervals[i] = (intervals[i][1], intervals[i][0], intervals[i][2])
    intervals.sort()
    f = [0] * (len(intervals) + 1)
    for i, (_, s, val) in enumerate(intervals):
        j = bisect_right(intervals, (s-1, inf), hi=i)
        f[i + 1] = max(f[i], f[j] + val)  #  # 为什么是 j 不是 j+1：上面算的是 > st，-1 后得到 <= st，但由于还要 +1，抵消了
    return f[-1]


def get(intervals):
    # 按区间的结束时间进行升序排序
    intervals.sort(key=lambda x: x[1])

    # 选择不重叠的区间
    res = []
    last = float('-inf')

    for interval in intervals:
        if interval[0] >= last:
            res.append(interval)
            last = interval[1]

    return res

def solve() -> None:
    print(get([(1,5), (2,6), (3,10), (4,5), (6,7)]))
    print(getw([(1, 2, 1), (2, 3, 3), (2, 7, 10), (6, 10, 1)]))
    
if __name__ == '__main__':
    solve()