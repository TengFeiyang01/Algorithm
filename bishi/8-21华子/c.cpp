#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> adj(10001);
    for (int i = 0, x, y; i < n; ++i) {
    	std::cin >> x >> y;
    	for (int j = 0; j < x - 1; ++j) {
    		int z;
    		std::cin >> z;
    		adj[y].push_back(z);
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
