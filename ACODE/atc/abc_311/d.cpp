#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
constexpr int dx[] = {0, 0, -1, 1};
constexpr int dy[] = {-1, 1, 0, 0};

void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> s[i];
    }

    std::vector st(n, std::vector<bool>(m));
    std::vector pass(n, std::vector<bool>(m));

    st[1][1] = true;
    pass[1][1] = true;
    std::queue<PII> q;
    q.emplace(1, 1);

    while (q.size()) {
    	auto[x, y] = q.front();
    	q.pop();

    	for (int k = 0; k < 4; ++k) {
    		int x0 = x, y0 = y;
    		while (s[x0][y0] == '.') {
    			pass[x0][y0] = true;
    			x0 += dx[k];
    			y0 += dy[k];
    		}
    		y0 -= dy[k];
    		x0 -= dx[k];
    		if (!st[x0][y0]) {
    			st[x0][y0] = true;
    			q.emplace(x0, y0);
    		}
    	}
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += pass[i][j];
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
