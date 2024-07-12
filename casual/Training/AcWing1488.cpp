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
    int n, m, k;
    std::cin >> n >> m;
    std::vector<PII> g[n + 1];
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	g[u].emplace_back(v, w);
    	g[v].emplace_back(u, w);
    }
    std::cin >> k;
    for (int i = 0; i < k; ++i) {
    	int x;
    	std::cin >> x;
    	g[0].emplace_back(x, 0);
    }

    std::vector<int> dist(n + 1, inf);
    dist[0] = 0;

    std::priority_queue<PII, std::vector<PII>, std::greater<PII> > pq;
    std::vector<int> vis(n + 1);
    pq.emplace(0, 0);

    while (pq.size()) {
    	auto[d, u] = pq.top(); pq.pop();
    	if (vis[u]) continue;
    	vis[u] = 1;
    	for (auto&[v, w] : g[u]) {
    		if (dist[v] > dist[u] + w) {
    			dist[v] = dist[u] + w;
    			pq.emplace(dist[v], v);
    		}
    	}
    }
    std::cin >> m; 
    for (int i = 1; i <= m; ++i) {
    	int x;
    	std::cin >> x;
    	std::cout << dist[x] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
