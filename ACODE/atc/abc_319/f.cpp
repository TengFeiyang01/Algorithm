#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int N;
    std::cin >> N;

    std::vector<int> p(N), t(N), s(N), g(N);
    p[0] = -1;

    std::vector<int> mask(N), id(N);
    std::vector<std::vector<int>> adj(N);
    std::vector<int> v;
    for (int i = 1; i < N; ++i) {
    	std::cin >> p[i] >> t[i] >> s[i] >> g[i];
    	p[i]--;
    	adj[p[i]].push_back(i);
    	if (t[i] == 2) {
    		id[i] = v.size();
    		v.push_back(i);
    	}
    }	

    int cur = 1;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
    std::vector<bool> vis(N);
    auto init = [&]() {
    	while (!q.empty()) {
    		q.pop();
    	}
    	cur = 1;
    	q.emplace(0, 0);
    	vis.assign(N, false);
    };

    auto bfs = [&](int mask, int inc = 0) {
    	while (!q.empty()) {
    		auto [v, x] = q.top();
			if (v > cur) {
				break;
			}    	
			q.pop();
			if (t[x] == 1 && inc) {
				cur = std::min(inf, cur + g[x]);
			}	
			vis[x] = true;
			for (auto y : adj[x]) {
				if (t[y] == 1 or (mask >> id[y] & 1)) {
					q.emplace(s[y], y);
				}
			}
    	}
    };

    const int M = v.size();
    std::vector<int> dp(1 << M);
    init();
    bfs(0, 1);
    dp[0] = cur;

    for (int mask = 1; mask < 1 << M; ++mask) {
    	for (int i = 0; i < M; ++i) {
    		if (mask >> i & 1) {
    			init();
    			cur = dp[mask ^ (1 << i)];
    			bfs(mask ^ (1 << i), 0);
    			if (vis[p[v[i]]]) {
    				for (auto y : adj[v[i]]) {
    					if (t[y] == 1) {
    						q.emplace(s[y], y);
    					}
    				}
    				cur = std::min(1LL * inf, 1LL * cur * g[v[i]]);
    				bfs(mask, 1);
    				dp[mask] = std::max(dp[mask], cur);
    			}
    		}
    	}
    }

    init();
    cur = dp.back();
    bfs((1 << M) - 1);
    if (q.empty()) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}