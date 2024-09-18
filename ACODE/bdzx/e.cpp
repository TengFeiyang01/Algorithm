#include <bits/stdc++.h>

using i64 = long long;
const i64 inf = 1e18;

void solve() {
    int n, cntPink = 0, cntOther = 0;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == 'P') {
    		cntPink++;
    	} else {
    		cntOther++;
    	}
    }
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	adj[x - 1].push_back(y - 1);
    	adj[y - 1].push_back(x - 1);
    }

    bool ok = false;

    std::vector<i64> dpOther(n), dpPink(n), siz(n), sizPink(n), sizOther(n);

    std::function<void(int, int, int)> dfs = [&](int u, int fa, int d) -> void {
    	siz[u] = 1;
    	if (s[u] == 'P') {
    		dpPink[0] += d;
    		sizPink[u]++;
    	} else {
	    	dpOther[0] += d;
    		sizOther[u]++;
    	}

    	for (auto v : adj[u]) {
    		if (v != fa) {
    			dfs(v, u, d + 1);
    			siz[u] += siz[v];
    			sizOther[u] += sizOther[v];
    			sizPink[u] += sizPink[v];
    		}
    	}
    	if (siz[u] == cntPink) {
   			ok = true;
   		}
    };

    dfs(0, -1, 0);
    if (!ok) {
    	std::cout << "-1\n";
    	return;
    }

    i64 ans = inf;
    if (siz[0] == cntPink) {
		std::cout << 0 << "\n";
		return;   	
    }

    std::function<void(int, int)> reroot = [&](int u, int fa) -> void {
    	for (auto v : adj[u]) {
    		if (v != fa) {
    			dpOther[v] = dpOther[u] - (2LL * sizOther[v]) + cntOther;
    			dpPink[v] = dpPink[u] - (2LL * sizPink[v]) + cntPink;
    			if (siz[v] == cntPink) {
    				if (ans > (dpPink[v] + dpOther[v]) / 2) {
    					ans = dpPink[v] + dpOther[v] >> 1;
    					std::cout << v + 1 << "\n";
    				}
    			}
    			reroot(v, u);
    		}
    	}
    };	

    reroot(0, -1);

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
