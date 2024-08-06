#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

/*
实际上可以枚举当前的城市，然后去计算当前的城市的油价一直到后面哪个城市都是最小的
设这个数为y，当前城市为x，那么从x到y+1中间的道路消耗的油都应该尽量在x加。
显然，对于每个城市的y是可以用O(n)的时间用单调栈处理出来的，那么剩下枚举也是O(n)了。
*/
/*
一个比较好写的思路大概是，一直保持油箱是满的
同时油箱看作分了很多块儿，每块的油价格是不一样的。
行驶过程中，先消耗便宜的油，每到一个加油站
可以把油箱中比当前油价贵的油换掉，换成当前的价格。这样也是利用一个单调栈，时间复杂度O(n)。
*/


// 结构体定义，用于存储每个节点的信息
struct Node {
    int num, cost;  // num表示该节点的油量，cost表示油价
};

// 主函数，用于解决最小加油费用问题
void solve() {
    int n, T;
    std::cin >> n >> T;  // 读取城市数量n和油箱容量T

    std::deque<Node> q;  // 双端队列，用于维护油价和油量信息
    int v = 0;           // 当前油量
    i64 ans = 0;         // 最小花费

    for (int i = 1; i <= n; ++i) {
        int d, c;
        std::cin >> d >> c;  // 读取到下一个城市的距离d和当前城市的油价c

        // 如果当前城市到下一个城市的距离大于油箱容量，则无法到达终点
        if (d > T) {
            std::cout << "-1\n";
            return;
        }

        // 维护一个递增的油价队列，移除比当前油价高的元素
        while (!q.empty() && q.back().cost >= c) {
            v -= q.back().num;  // 减去被移除节点的油量
            q.pop_back();       // 移除队列尾部元素
        }

        // 将当前节点的油价和可以加的油量推入队列
        q.push_back({T - v, c});
        v = T - d;  // 更新当前油量

        // 消耗油量到达下一个城市
        while (d > 0) {
            int use = std::min(d, q.front().num);  // 计算需要消耗的油量
            d -= use;                              // 更新剩余距离
            q.front().num -= use;                  // 更新队列头部节点的油量
            ans += (i64)use * q.front().cost;      // 计算花费

            // 如果队列头部节点的油量消耗完，移除该节点
            if (q.front().num == 0) {
                q.pop_front();
            }
        }
    }

    // 输出最小花费
    std::cout << ans << "\n";
}
/*
void solve() {
    i64 n, t;
    std::cin >> n >> t;
    std::vector<i64> D(n + 1), P(n + 1), S(n + 1), r(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> D[i] >> P[i];
        S[i] = S[i - 1] + D[i];
    }

    std::stack<int> st;

    for (int i = n; i >= 1; --i) {
        if (D[i] > t) {
            std::cout << "-1\n";
            return;
        }
        while (!st.empty() && P[st.top()] >= P[i]) {
            st.pop();
        }
        if (st.empty()) {
            r[i] = n + 1;
        } else {
            r[i] = st.top();
        }
        st.push(i);
    }

    i64 ans = 0, now = 0;
    for (int i = 1; i <= n; ++i) {
        i64 mx = S[r[i] - 1] - S[i - 1];
        i64 dif = std::min(t, mx) - now;
        if (dif <= 0) {
            now -= D[i];
            continue;
        }
        // 加满
        now += dif;
        // 跑到下一个点
        now -= D[i];
        // 这次加的油价格
        ans += P[i] * dif;
    }
    std::cout << ans << "\n";

}*/

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}


