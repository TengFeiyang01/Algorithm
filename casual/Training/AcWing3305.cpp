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
	int n, m, k, T;
	std::cin >> n >> m >> k >> T;
	std::vector<int> w(n);
	std::vector<PII> g[n];
	for (int i = 0; i < n; ++i) std::cin >> w[i];
	std::vector<int> dist(n, inf), st(n);
	std::queue<int> q;

	while (m--) {
		int x;
		std::cin >> x;
		x--;
		q.push(x);
		dist[x] = 0;
		st[x] = 1;
	}

	while (k--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		a--, b--, c--;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}    


	while (q.size()) {
		int x = q.front();
		q.pop();
		st[x] = 0;

		for (auto&[y, z] : g[x]) {
			if (dist[z] > std::max(dist[x], dist[y]) + std::max(w[x], w[y])) {
				dist[z] = std::max(dist[x], dist[y]) + std::max(w[x], w[y]);
				if (!st[z]) {
					q.push(z);
					st[z] = 1;
				}
			}
		}
	}
	std::cout << dist[T - 1];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
