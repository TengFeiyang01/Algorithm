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
const int N = 2e5 + 13;
int n, k;
std::vector<int> g[N];
int h[N];
bool ok;

void dfs(int u, int depth, int fa) {
	h[u] = 1;
	for (auto v : g[u]) {
		dfs(v, depth, u);
		h[u] = std::max(h[u], h[v] + 1);
	}
	if (h[u] == depth && fa != 1) {
		k--;
		if (k < 0) ok = false;
		h[u] = 0;
	}
}


void solve() {
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) g[i].clear(), h[i] = 0;
	for (int i = 2; i <= n; ++i) {
		int v;
		std::cin >> v;
		g[v].push_back(i);
	}
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		int cnt = k;
		ok = true;
		dfs(1, mid, 1);
		if (ok) r = mid;
		else l = mid + 1;
		k = cnt;
	}
	std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
