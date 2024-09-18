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

//堆优化的Dijkstra 每次到达当前点时，待等待结束再更新其他点
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::unordered_set<int> ban[n + 1];
    std::vector<PII> g[n + 1];
    for (int i = 0; i < m; ++i) {
    	int x, y, w;
    	std::cin >> x >> y >> w;
    	g[x].emplace_back(y, w);
    	g[y].emplace_back(x, w);
    }
    for (int i = 1; i <= n; ++i) {
    	int k;
    	std::cin >> k;
    	while (k--) {
			int x;
			std::cin >> x;
	    	ban[i].insert(x);
    	}
    }
    std::vector<int> dist(n + 1, inf), st(n + 1, 0);
    std::priority_queue<PII, std::vector<PII>, std::greater<PII> > pq;
    pq.emplace(0, 1);
    dist[1] = 0;
    st[1] = 0;
    while (pq.size()) {
        auto[d, t] = pq.top();
        pq.pop();
        if (st[t]) continue;
        st[t] = 1;
        int k = 0;
        while (ban[t].count(d)) {
            d++;
        }

        for (auto [v, w] : g[t]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    if (dist[n] == inf) {
        std::cout << "-1\n";
    } else {
        std::cout << dist[n];
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
