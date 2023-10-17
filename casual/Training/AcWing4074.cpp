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
    int n, m;
    std::cin >> n >> m;
    std::vector g(n, std::vector<int>(n, inf));
    std::vector t(n, std::vector<int>(n, inf));
    for (int i = 0; i < n; ++i) g[i][i] = t[i][i] = 0;

    while (m--) {
    	int u, v;
    	std::cin >> u >> v;
    	u--, v--;
        t[u][v] = t[v][u] = 1;
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (t[i][j] != 1 && t[j][i] != 1)
                g[i][j] = g[j][i] = 1;

    for (int k = 0; k < n; ++k)
    	for (int i = 0; i < n; ++i)
    		for (int j = 0; j < n; ++j) {
    			g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
    			t[i][j] = std::min(t[i][j], t[i][k] + t[k][j]);
    		}
    if (t[0][n - 1] == inf || g[0][n - 1] == inf) {
        std::cout << "-1";
    } else std::cout << std::max(t[0][n - 1], g[0][n - 1]);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
