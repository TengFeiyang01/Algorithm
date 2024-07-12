#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    i64 k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	--x, --y;
    	adj[x].push_back(y);
    }

    auto check = [&](int x) -> bool {
    	std::vector<int> deg(n);
    	int left = n;
    	for (int i = 0; i < n; ++i) {
    		if (a[i] > x) {
    			left--;
    			continue;
    		}
    		for (auto j : adj[i]) {
    			if (a[j] <= x) {
    				deg[j]++;
    			}
    		}
    	}
    	std::queue<int> q;
    	for (int i = 0; i < n; ++i) {
    		if (a[i] <= x and deg[i] == 0) {
    			q.push(i);
    		}
    	}
    	std::vector<int> f(n);
    	int mxf = 0;
    	while (q.size()) {
    		left--;
    		int u = q.front();
    		q.pop();
    		f[u]++;
    		mxf = std::max(mxf, f[u]);
    		for (auto v : adj[u]) {
    			if (a[v] > x) {
                    continue;
                } 
                f[v] = f[u];
                if (--deg[v] == 0) {
                    q.push(v);
                }
    		}
    	}
    	return left > 0 || mxf >= k;
    };
    
    int l = 0, r = inf;
    while (l < r) {
    	int mid = l + r >> 1;
    	if (check(mid)) {
    		r = mid;
    	} else {
    		l = mid + 1;
    	}
    }

    if (l >= inf) l = -1;
    std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
