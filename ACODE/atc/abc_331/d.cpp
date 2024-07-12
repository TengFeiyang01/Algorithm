#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector sum(n + 1, std::vector<i64>(n + 1));
    for (int i = 1; i <= n; ++i) {
    	std::string s;
    	std::cin >> s;
    	s = " " + s;
    	for (int j = 1; j <= n; ++j) {
    		sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + i64(s[j] == 'B');
    	}
    }

    auto calc = [&](i64 x, i64 y) ->i64 {
    	i64 cntx = x / n, cnty = y / n;
    	i64 ans = 1LL * sum[n][n] * cntx * cnty;
        x %= n;
        y %= n;
    	ans += cnty * sum[x][n];
    	ans += cntx * sum[n][y];
    	ans += sum[x][y];
    	return ans;
    };

    for (int i = 0; i < m; ++i) {
    	int x1, x2, y1, y2;
    	std::cin >> x1 >> y1 >> x2 >> y2;

    	i64 ans = calc(x2 + 1, y2 + 1) - calc(x2 + 1, y1) - calc(x1, y2 + 1) + calc(x1, y1);
    	std::cout << ans << "\n";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
