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
#include <stack>
#include <numeric>
#include <cmath>
 
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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> g[n];
	std::vector f(n, std::vector<int>(3));
	std::vector<int> w(n);
	std::vector<int> st(n);
    for (int i = 0; i < n; ++i) {
		int u, v, cnt;
		std::cin >> u >> w[--u] >> cnt;
		while (cnt--) {
			std::cin >> v;
			g[u].eb(--v);
			st[v] = 1;
		}
    }

    std::function<void(int)> dfs = [&](int u) {
		f[u][0] = 0;
		f[u][2] = w[u];
		for (int v : g[u]) {
			dfs(v);
			f[u][0] += std::min(f[v][1], f[v][2]);
			f[u][2] += std::min({f[v][0], f[v][1], f[v][2]});
		}
		f[u][1] = inf;
		for (int v : g[u]) {
			f[u][1] = std::min(f[u][1], f[u][0] + f[v][2] - std::min(f[v][1], f[v][2]));
		}
    };

	int root = 0;
	while (st[root]) root++;

	dfs(root);

	std::cout << std::min(f[root][1], f[root][2]);

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
