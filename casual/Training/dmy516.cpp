#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, std::vector<std::array<int, 2>>> cnt;
    for (int i = 0; i < n; ++i) {
    	int a, m;
    	std::cin >> a >> m;
    	for (int j = 2; j * j <= m; ++j) {
    		if (m % j == 0) {
    			int p = 1;
    			while (m % j == 0) {
    				m /= j;
    				p *= j;
    			}
    			cnt[j].push_back({p, a % p});
    		}
    	}
    	if (m > 1) cnt[m].push_back({m, a % m});
    }
    for (auto v : cnt) {
        auto va = v.second;
    	auto x = (*std::max_element(va.begin(), va.end()))[1];
    	for (auto y : va) {
    		if (x % y[0] != y[1]) {
    			std::cout << "No\n";
    			return;
    		}
    	}
    }
    std::cout << "Yes\n";
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
