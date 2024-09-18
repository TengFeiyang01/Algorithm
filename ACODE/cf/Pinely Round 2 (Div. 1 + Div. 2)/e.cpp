    #include <bits/stdc++.h>

    const int inf = 0x3f3f3f3f;
    using i64 = long long;

    void solve() {
        int n, m, k;
        std::cin >> n >> m >> k;
        std::vector<std::vector<int>> adj(n);
        std::vector<int> h(n), d(n);
        std::vector<i64> dp(n);
        for (int i = 0; i < n; ++i) {
        	std::cin >> h[i];
        }
        for (int i = 0; i < m; ++i) {
        	int x, y;
        	std::cin >> x >> y;
        	--x, --y;
        	adj[x].push_back(y);
        	d[y]++;
        }

        std::vector<int> q;
        for (int i = 0; i < n; ++i) {
        	if (d[i] == 0) {
        		q.push_back(i);
        	}
        }

        for (int i = 0; i < n; ++i) {
            int x = q[i];
            for (auto y : adj[x]) {
                if (--d[y] == 0) {
                    q.push_back(y);
                }
            }
        }   

        for (int i = n - 1; i >= 0; --i) {
            int x = q[i];
            for (auto y : adj[x]) {
                dp[x] = std::max(dp[x], dp[y] + (h[y] - h[x] + k) % k);
            }
        }
        
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        std::sort(p.begin(), p.end(),
            [&](int i, int j) {
                return h[i] < h[j];
            });
        i64 ans = 1E18;
        for (int i = 0; i < n; i++) {
            dp[i] += h[i];
        }
        i64 res = std::ranges::max(dp);
        
        for (auto i : p) {
            ans = std::min(ans, res - h[i]);
            res = std::max(res, dp[i] + k);
        }
        std::cout << ans << "\n";
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