#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;


void solve() {
    int n, m, x;
    std::cin >> n >> m >> x;
    std::vector<std::string> s(n);

    for (int i = 0; i < n; ++i) {
    	std::cin >> s[i];
    }

    std::vector<std::vector<i64>> g(26, std::vector<i64>(26, inf));
    for (int i = 0; i < m; ++i) {
    	char u, v;
    	i64 w;
    	std::cin >> u >> v >> w;
    	u -= 'a';
    	v -= 'a';
    	g[u][v] = std::min(g[u][v], w);
    }
    
    for (int i = 0; i < 26; ++i) g[i][i] = 0;

    for (int k = 0; k < 26; ++k) {
    	for (int i = 0; i < 26; ++i) {
    		for (int j = 0; j < 26; ++j) {
    			g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
    		}
    	}
    }
    for (int i = 0; i < 26; ++i) {
    	for (int j = 0; j < 26; ++j) {
    		g[i][j] = std::min(g[i][j], x);
    	}
    }
    i64 ans = 0;
    // 四个角相等
    for (int i = 0; i < n / 2; ++i) {
    	for (int j = 0; j < n / 2; ++j) {
    		i64 t = inf;
    		for (int k = 0; k < 26; ++k) {
    			int a = s[i][j] - 'a', b = s[n - 1 - i][j] - 'a';
    			int c = s[n - 1 - i][n - 1 - j] - 'a', d = s[i][n - 1 - j] - 'a';
    			t = std::min(t, g[a][k] + g[b][k] + g[c][k] + g[d][k]);
    		}
    		ans += t;
    	}
    }
    if (n % 2) {
    	int p = (n + 1) / 2;
    	for (int i = 0; i < n / 2; ++i) {
    		i64 t = inf;
    		for (int k = 0; k < 26; ++k) {
    			int a = g[i][p] - 'a', b = g[n - i - 1][p] - 'a';
    			t = std::min(t, g[a][k] + g[b][k]);
    		}
    		ans += t;
    	}
    	for (int i = 0; i < n / 2; ++i) {
    		i64 t = inf;
    		for (int k = 0; k < 26; ++k) {
    			int a = g[p][i] - 'a', b = g[p][n - i - 1] - 'a';
    			t = std::min(t, g[a][k] + g[b][k]);
    		}
    		ans += t;
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
