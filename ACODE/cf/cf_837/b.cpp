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
const int N = 1e5 + 13;
int n, m;

//对每个人 i 维护他最大的不认识的人的下标 那么以 i 为结尾的区间内互相认识的为 i - j = i - (j + 1) + 1 对
//且 j 随着 i 的增大而增大
 
void solve() {
	int u, v;
	std::cin >> n >> m;
	std::vector<std::vector<int>> g(n + 1);
	while (m--) {
		std::cin >> u >> v;
		if (u < v) std::swap(u, v);
		g[u].emplace_back(v);
	}
	ll ans = 0ll;
	for (int i = 1, j = 0; i <= n; ++i) {
		for (auto v : g[i]) j = std::max(j, v);
		ans += i - j;
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
