#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
    	std::cin >> a[i];
    }

    std::vector<std::vector<int>> adj(n);

	for (int i = 0; i < n; ++i) {
		i64 x = a[i];
		for (int j = 2; j < n and j < x; ++j) {
			if (x % j == 0) {
				if (i - j >= 0) {
					adj[i].push_back(i - j);
				}
				if (i + j < n) {
					adj[i].push_back(i + j);
				}
			}
		}
	}

	std::vector<bool> vis(n);
	std::queue<std::pair<int, int>> q;
	q.emplace(0, 0);
	vis[0] = true;
	
	while (!q.empty()) {
		auto [u, d] = q.front();
		q.pop();
		std::cout << u << " " << d << " " << n - 1 << "\n";
		if (u == n - 1) {
			std::cout << d << "\n";
			return;
		}		
		for (auto v : adj[u]) {
			if (vis[v]) continue;
			q.emplace(v, d + 1);
			vis[v] = true;
		}
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
