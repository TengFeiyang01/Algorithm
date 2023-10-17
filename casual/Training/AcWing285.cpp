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

using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];

void solve() {
    std::cin >> n;
    std::vector<int> happy(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> happy[i];
    std::vector<int> indg(n + 1, 0);
	std::vector<int> g[n + 1];
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		g[v].emplace_back(u);
		indg[u]++;
	}
	int start = 0;
	for (int i = 1; i <= n; ++i) if (indg[i] == 0) start = i;

	int f[n + 1][2]{0};

	std::function<void(int)> dfs = [&](int u) {
		f[u][1] = happy[u];
		for (auto v : g[u]) {
			dfs(v);

			f[u][0] += std::max(f[v][0], f[v][1]);
			f[u][1] += f[v][0];
		}
	};
	dfs(start);

	std::cout << std::max(f[start][0], f[start][1]);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
