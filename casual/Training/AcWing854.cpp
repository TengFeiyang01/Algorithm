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
const int N = 222 + 13;

void solve() {
	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector d(N, std::vector<int>(N, inf));
	for (int i = 1; i <= n; ++i) d[i][i] = 0;
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		std::cin >> u >> v >> w;
		d[u][v] = std::min(d[u][v], w);
	}
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		if (d[x][y] > inf / 2) std::cout << "impossible\n";
		else std::cout << d[x][y] << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
