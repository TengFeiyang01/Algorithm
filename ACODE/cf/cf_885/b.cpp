#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> c(n);
    std::vector pos(k, std::vector<int>(1, -1));
    for (int i = 0; i < n; ++i) {
    	std::cin >> c[i];
    	pos[c[i] - 1].push_back(i);
    }

    auto calc = [&](std::vector<int> &a) {
    	std::vector<int> g;
    	for (int i = 1; i < a.size(); ++i) {
    		g.push_back(a[i] - a[i - 1]);
    	}
    	std::sort(g.begin(), g.end());
    	std::reverse(g.begin(), g.end());
    	if (g.size() == 1) {
    		return g[0] - 1;
    	}
    	return std::max(g[1] - 1, (g[0] - 1) / 2);
    };


    int ans = inf;
    for (int i = 0; i < k; ++i) {
    	pos[i].push_back(n);
    	ans = std::min(ans, calc(pos[i]));
    }
    std::cout << ans << "\n";
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
