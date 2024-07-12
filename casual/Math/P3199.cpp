#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, double>>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int u, v;
        double w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	adj[u].emplace_back(v, w);
    }
    std::vector<double> dist(n);
   	std::vector<bool> st(n);

    std::function<bool(int, double)> spfa = [&](int u, double mid) ->bool {
    	st[u] = true;
    	for (auto [v, w] : adj[u]) {
    		if (dist[v] > dist[u] + w - mid) {
    			dist[v] = dist[u] + w - mid;
    			if (st[v] or spfa(v, mid)) return true;
    		}
    	}
    	st[u] = false;
    	return false;
    };

    auto check = [&](double x) {
    	dist.assign(n, 0);
    	st.assign(n, false);
    	for (int i = 0; i < n; ++i) {
    		if (spfa(i, x)) {
    			return true;
    		}
    	}
    	return false;
    };


    double l = -1e7, r = 1e7;
    for (int i = 0; i < 100; ++i) {
    	double mid = (l + r) / 2.0;
    	if (check(mid)) {
    		r = mid;
    	} else {
    		l = mid;
    	}
    }
    std::cout << std::fixed << std::setprecision(8) << r << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
