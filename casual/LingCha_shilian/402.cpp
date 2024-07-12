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

//http://oj.daimayuan.top/course/5/problems

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> g[n];
    std::vector<ll> w(n);
    for (int i = 1; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	g[x - 1].push_back(i);
    }
    for (ll& v : w) std::cin >> v;

    std::vector<std::array<ll, 2>> dp(n);

    std::function<void(int, int)> dfs = [&](int u, int fa) {
        dp[u][1] = w[u];
    	int s = 0;
    	for (int &v : g[u]) {
    		if (v != fa) {
    			dfs(v, u);
		    	dp[u][0] += std::max(dp[v][0], dp[v][1]);
		    	dp[u][1] += dp[v][0];
    		}
    	}
    };
    dfs(0, -1);
    std::cout << std::max(dp[0][0], dp[0][1]);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
