#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr i64 INF = 1e18;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int cs = 1;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> adj[n], dep(n);
    dep[0] = 0;
    for (int i = 1; i < n; ++i) {
    	int fa;
    	std::cin >> fa;
    	adj[fa - 1].push_back(i);
    	dep[i] = dep[fa - 1] + 1;
    }

    std::vector<std::vector<i64>> dp(n, std::vector<i64>(2, INF));

    //dp[u][0]: 从u点出发回到 u 点的代价
    //dp[u][1]: 至少存在一条从根节点出发到 u 点的代价

    std::function<void(int)> dfs = [&](int u) {
    	// dp[u][1]:表示至少存在一条路径从根节点到u这个子树
    	//采用类似背包的合并，初始化的话只有u一个节点，所以f[u][1]就是depth[u]
    	dp[u][1] = dep[u];
    	dp[u][0] = 0;
    	for (auto &v : adj[u]) {
    		dfs(v);
	    	// 这里首先保证dp[u][1]和dp[u][0]的更新顺序，因为dp[u][1]要用到dp[u][0]之前的值
	        // dp[u][1]要保证至少存在一条路径来自根，那么就是dp[u][1]+dp[v][1]前面的背包和后面的背包都存在
	        // dp[u][1] + dp[v][0] + 2前面的背包不存在后面的背包存在
	        // dp[u][0] + dp[v][1] 前面的背包不存在但是后面的背包存在

	        //dp[u][0] + dp[v][1]： dp[u][0] 是除了v以外回来的代价 即1->u u->u u->v 其中 1->u + u->v ==dp[v][1]
	        //dp[u][1] + dp[v][0] + 2: dp[u][1] 除了v以外的 包含从根开始的代价 再加上u->v v->u + dp[v][0]
    		dp[u][1] = std::min({dp[u][1] + dp[v][1], dp[u][1] + dp[v][0] + 2, dp[u][0] + dp[v][1]});
    		dp[u][0] += dp[v][0] + 2;
    	}
    };

    dfs(0);

    std::cout << "Case #" << cs++ << ": " << std::min(dp[0][0], dp[0][1]) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
