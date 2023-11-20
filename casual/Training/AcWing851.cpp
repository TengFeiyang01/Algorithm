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
    std::vector<PII> g[n];

    for (int i = 0; i < ; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	g[u - 1].emplace_back(v - 1, w);
    }
    std::vector<int> d(n, inf), st(n);
    std::queue<int> q;
    q.push(0);
    st[0] = 1;
    d[0] = 0;

    while (sz(q)) {
    	auto u = q.front();
    	q.pop();

    	st[u] = 0;

    	for (auto[v, w] : g[u]) {
    		if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
    			if (!st[v]) {
    				q.push(v);
    				st[v] = 1;
    			}
    		}
    	}
    } 
    if (d[n - 1] == inf) {
    	std::cout << "impossible";
    } else {
    	std::cout << d[n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
