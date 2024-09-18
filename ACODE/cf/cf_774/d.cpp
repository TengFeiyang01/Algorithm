#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

struct Node {
	int sum, cnt;
	bool operator>(const Node& b) const {
		if (cnt != b.cnt) return cnt > b.cnt;
		return sum < b.sum;
	}
};

//dp[u][0/1] 表示以u为根的子树中，u为好点/坏点的情况下，所能构成的好点的最大数目以及最小消费 

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> g[n];
    std::vector<int> ans(n);
    std::vector dp(n, std::vector<Node>(2));

    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	u--, v--;
    	g[u].emplace_back(v);
    	g[v].emplace_back(u);
    }
    
    if (n == 2) {
    	std::cout << "2 2\n1 1\n";
    	return;
    }

    std::function<void(int, int)> dfs = [&](int u, int fa) ->void {
    	dp[u][1].cnt = 1;
    	dp[u][1].sum = g[u].size();
    	dp[u][0].sum = 1;

    	for (auto &v : g[u]) {
    		if (v == fa) continue;
    		dfs(v, u);

    		dp[u][1].cnt += dp[v][0].cnt;
    		dp[u][1].sum += dp[v][0].sum;

    		int p = dp[v][1] > dp[v][0];
    		dp[u][0].cnt += dp[v][p].cnt;
    		dp[u][0].sum += dp[v][p].sum;
    	}
    };

    dfs(0, -1);
    std::function<void(int, int, int)> dfs1 = [&](int u, int fa, int p) ->void {
    	ans[u] = p ? g[u].size() : 1;
    	for (auto &v : g[u]) {
    		if (v == fa) continue;

    		if (p) dfs1(v, u, 0);
    		else {
    			dfs1(v, u, dp[v][1] > dp[v][0]);
    		}
    	}
    };
    
    int p = dp[0][1] > dp[0][0];
    dfs1(0, -1, p);

    std::cout << dp[0][p].cnt << " " << dp[0][p].sum << "\n";
    for (int i = 0; i < n; ++i) {
    	std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
	
	solve();

    return 0;
}
