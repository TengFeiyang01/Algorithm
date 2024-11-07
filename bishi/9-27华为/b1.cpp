#include <bits/stdc++.h>

using i64 = long long;
const i64 inf = 1e18;
void print(auto const& seq) {
    for (auto const& elem : seq) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}
int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
	
	int a, b, c, n;
	std::cin >> a >> b >> c >> n;
	std::vector<i64> dp(n, inf);
	std::map<int, std::vector<int>> adj;
	std::vector<std::vector<int>> st(n);

	for (int i = 0; i < n; ++i) {
		int t;
		std::cin >> t;
		for (int j = 0, x; j < t; ++j) {
			std::cin >> x;
			st[i].push_back(x);
			adj[x].push_back(i);
		}
	}

	std::queue<int> q;
	for (auto x : adj[b]) {
		dp[x] = 0;
		q.push(x);
	}

	while (q.size()) {
		int u = q.front();
		q.pop();
		for (auto p : st[u]) {
			for (auto v : adj[p]) {
				if (dp[v] > dp[u] + 1) {
					dp[v] = dp[u] + 1;
					q.push(v);
				}
			}
		}
	}
	print(dp);

	i64 x = inf, y = inf;
	for (int p : adj[a]) {
		x = std::min(x, dp[p]);
	}
	for (int p : adj[c]) {
		y = std::min(y, dp[p]);
	}
    
    if (x + y > inf) {
    	std::cout << "-1\n";
    } else {
    	std::cout << (x + y + 1) << "\n";
    }

    return 0;
}
