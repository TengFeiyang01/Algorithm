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
const int N = 100 + 13;

int w[N][N], level[N];
bool st[N];
int dist[N];
int n, m;	

int dijkstra(int down, int up) {
	memset(dist, inf, sizeof dist);
	memset(st, 0, sizeof st);
	
	dist[0] = 0;
	for (int i = 1; i <= n + 1; ++i) {
		int t = -1;
		for (int j = 0; j <= n; ++j) 
			if (!st[j] && (t == -1 || dist[t] > dist[j])) 
				t = j;
		st[t] = true;
		for (int j = 1; j <= n; ++j) {
			if (level[j] >= down and level[j] <= up) {
				dist[j] = std::min(dist[j], dist[t] + w[t][j]);	
			}
		}
	}
	return dist[1];	
}


void solve() {
	std::cin >> m >> n;
	memset(w, inf, sizeof w);
	for (int i = 1; i <= n; ++i) {
		w[i][i] = 0;
	}

	for (int i = 1; i <= n; ++i) {
		int p, cnt;
		std::cin >> p >> level[i] >> cnt;
		w[0][i] = std::min(p, w[0][i]);
		while (cnt--) {
			int id, cost;
			std::cin >> id >> cost;
			w[id][i] = std::min(cost, w[id][i]);
		}
	}
	int res = inf;
	for (int i = level[1] - m; i <= level[1]; ++i) {
		res = std::min(res, dijkstra(i, i + m));
	}

	std::cout << res << "\n";
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cin.tie(0);

	solve();

	return 0;
}
