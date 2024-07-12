#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector a(n, std::vector<int>(m));
    std::map<int, i64> preX, preY, cntX, cntY;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> a[i][j];
    	}
    }
    i64 ans = 0;
    for (int j = 0; j < m; ++j) {
    	for (int i = 0; i < n; ++i) {
    		ans += 1LL * j * cntX[a[i][j]] - preX[a[i][j]];
    		preX[a[i][j]] += j;
    		cntX[a[i][j]]++;
    	}
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		ans += 1LL * i * cntY[a[i][j]] - preY[a[i][j]];
    		preY[a[i][j]] += i;
    		cntY[a[i][j]]++;
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
