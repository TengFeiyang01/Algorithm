#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::map<i64, i64> cnt[4];
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
    	i64 x, y;
    	std::cin >> x >> y;
    	ans += cnt[0][x] + cnt[1][y];
    	ans += cnt[2][x - y] + cnt[3][y + x];
    	cnt[0][x]++;
    	cnt[1][y]++;
    	cnt[2][x - y]++;
    	cnt[3][x + y]++;
    }
    std::cout << ans * 2 << "\n";

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
