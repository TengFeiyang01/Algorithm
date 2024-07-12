#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 3e5 + 13;
int n, m;
std::vector<PII> g[N];
int d[N], ind[N];
ll dp[N][2];

/*
	dp[i][0]表示处理到第i个结点，且当前结点选了严格小于 di 条边所构成子树的最大权值和
	dp[i][1]表示处理到第i个结点，且当前结点选了不超过 di 条边所构成子树的最大权值和。

	如果不选这条边，那么转移为 dp[u][0]+=dp[v][1], dp[u][1]+=dp[v][1]，代表直接选择了子节点的最优情况。
	如果选了这条边，那么转移为 dp[u][0]+=dp[v][0]+w ,dp[u][1]+=dp[v][0]+w ，代表选择了子节点的次优情况，并再加上uv边使得权值和达到最优。
*/


//可以考虑先假设一条边都没选，意味着此时所有子节点都通过情况一的方式转移到父节点。如果我们要将其中一个子结点v的转移方式从情况一变为情况二
//根据两种转移式，这时结果增加 dp[v][0] + w − dp[v][1]
void dfs(int u, int fa) {
	std::vector<ll> record;
	for (auto&[v, w] : g[u]) {
		if (v == fa) continue;
		dfs(v, u);
		//假设不选边
		dp[u][0] += dp[v][1];
		dp[u][1] += dp[v][1];
		record.emplace_back(dp[v][0] + w - dp[v][1]);
	}
	std::sort(record.begin(), record.end(), std::greater<ll>());
	for (int i = 0; i < record.size(); ++i) {
		if (record[i] <= 0) continue;
		//选边
		if (i < d[u] - 1) dp[u][0] += record[i];
		if (i < d[u]) dp[u][1] += record[i];
	}
	if (d[u] == 0) dp[u][0] = -1e18;
}

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> d[i];
    for (int i = 1; i < n; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	g[u].emplace_back(v, w);
    	g[v].emplace_back(u, w);
    	ind[v]++;
    }
    int start = 0;
    for (int i = 1; i <= n; ++i) if (ind[i] == 0) start = i;
    dfs(start, -1);
	std::cout << dp[start][1];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
