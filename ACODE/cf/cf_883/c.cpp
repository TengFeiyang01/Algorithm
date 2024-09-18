#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m, h;
    std::cin >> n >> m >> h;
    std::vector a(n, std::vector<i64>(m));

    std::vector<std::array<i64, 3>> b;

    for (int i = 0; i < n; ++i) {
    	for (auto &x : a[i]) {
    		std::cin >> x;
    	}
    	std::sort(a[i].begin(), a[i].end());
    	i64 now = 0, cnt = 0, tot = 0;
    	for (int j = 0; j < m; ++j) {
    		if (a[i][j] + now <= h) {
    			now += a[i][j];
                tot += now;
    			cnt++;
    		}
    	}
    	b.push_back({-cnt, tot, i});
    }

    std::sort(b.begin(), b.end());

    for (int i = 0; i < n; ++i) {
    	if (b[i][2] == 0) {
    		std::cout << i + 1 << "\n";
    	}
    }
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
