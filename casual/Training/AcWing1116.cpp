#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};


void solve() {
    int n, m, x, y, ans = 0;
    std::cin >> n >> m >> x >> y;
    std::vector st(n, std::vector<int>(m, 0));
    std::function<void(int, int, int)> dfs = [&](int x, int y, int cnt) {
    	if (cnt == n * m) {
    		ans++;
    		return;
    	}
    	st[x][y] = 1;
    	for (int i = 0; i < 8; ++i) {
    		int a = x + dx[i], b = y + dy[i];
    		if (a < 0 || b < 0 || b >= m || a >= n || st[a][b]) continue;
    		dfs(a, b, cnt + 1);
    	}
    	st[x][y] = 0;
    };
    dfs(x, y, 1);
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
