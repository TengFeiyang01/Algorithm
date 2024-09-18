#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < N; ++i) {
    	int C;
    	std::cin >> C;
    	for (int j = 0; j < C; ++j) {
    		int x;
    		std::cin >> x;
    		adj[i].push_back(--x);
    	}
    }

    std::vector<bool> vis(N);
    auto rec = [&](auto self, int x) -> void {
    	if (vis[x]) {
    		return;
    	}
    	for (auto y : adj[x]) {
    		self(self, y);
    	}
    	vis[x] = true;
    	if (x) {
    		std::cout << x + 1 << " ";
    	}
    };
    rec(rec, 0);
    std::cout << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
