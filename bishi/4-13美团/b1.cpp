#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> a[i][j];
    	}
    }
    int ans = 0;
    for (int i = 1; i < n; ++i) {
    	for (int j = 1; j < m; ++j) {
    		if (a[i][j] == a[i - 1][j] and a[i - 1][j] == a[i - 1][j - 1] and a[i - 1][j - 1] == a[i][j - 1]) {
    			ans++;
    		}
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
