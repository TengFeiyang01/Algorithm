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

void solve() {
    int x1, x2, y1, y2, n;
    std::cin >> n;
    std::vector g(n, std::vector<char>(n));
    std::vector st(n, std::vector<bool>(n));
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < n; ++j)
    		std::cin >> g[i][j];
        
    std::function<int(int, int)> dfs = [&](int x, int y) ->int {
    	if (x < 0 || y < 0 || x >= n || y >= n || g[x][y] == '#' || st[x][y]) return 0;
        st[x][y] = true;
    	if (x == x2 && y == y2) return 1;
    	return dfs(x + 1, y) | dfs(x, y + 1) | dfs(x, y - 1) | dfs(x - 1, y);
    };

    std::cin >> x1 >> y1 >> x2 >> y2;

    if (dfs(x1, y1)) std::cout << "YES\n";
    else std::cout << "NO\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
