#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    scanf("%d", &n);
    std::vector<int> g[n];
    for (int i = 1; i < n; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --v, --u;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::vector<std::array<int, 3>> dp(n);
    std::function<void(int, int)> dfs = [&](int u, int p) ->void {
        /*
        dp[u][0]： 选u，其子节点选或不选都可以
        dp[u][2]： 不选u，u被其父节点覆盖
        dp[u][1]： 不选u，u被其子节点覆盖（仅当有子节点的时候才更新，默认inf），此时其子节点必须选一个
        */
        dp[u][0] = 1;
        dp[u][1] = inf;
        int dif = inf, tmp = 0, ok = 0;
        for (auto v : g[u]) {
            if (v == p) continue;
            ok = 1;
            dfs(v, u);
            dif = std::min(dp[v][0] - dp[v][1], dif);
            dp[u][0] += std::min({dp[v][0], dp[v][1], dp[v][2]});
            dp[u][2] += std::min(dp[v][0], dp[v][1]);
            tmp += std::min({dp[v][0], dp[v][1]});
        }
        if (ok) {
            //如果子节点选比不选优的话，dif为负数，否则为 >0 的数
            //如果dif小于0，说明存在子节点选比不选优，无需改变。 
            //否则需要将一个结点由不选变为选，我们加上变化最小的那个即可
            dp[u][1] = tmp + std::max(dif, 0);
        }
    };

    dfs(0, -1);
    std::cout << std::min({dp[0][0], dp[0][1]}) << "\n";
}

int main() {

    solve();

    return 0;
}
