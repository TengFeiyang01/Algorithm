#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> adj(n);

    for (int i = 1; i < n; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
    	for (auto x : adj[i]) {
    		for (auto y : adj[i]) {
    			if (i != y and i != x and x != y and s[i] == s[x] and s[x] == s[y]) {
    				ok = false;
    			}
    		}
    	}
    }
    if (ok) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
