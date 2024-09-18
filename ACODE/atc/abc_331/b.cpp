#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, s, m, l;
    std::cin >> n >> s >> m >> l;
    int ans = inf;
    for (int i = 0; i <= (n + 5) / 6; ++i) {
    	for (int j = 0; j <= (n + 7) / 8; ++j) {
    		for (int k = 0; k <= (n + 11) / 12; ++k) {
    			if (6 * i + 8 * j + 12 * k >= n) {
    				ans = std::min(ans, i * s + j * m + l * k);
    			}
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
