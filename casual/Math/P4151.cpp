#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

// 高斯消元法
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a;
    std::vector<std::vector<std::pair<int, i64>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    std::vector<i64> p(64), xr(n);
    // 答案必然是树上的一些环和一条主路径构成的
    std::vector<bool> in(n);
    std::function<void(int, int, i64)> dfs = [&](int u, int fa, i64 res) {
        in[u] = true, xr[u] = res;
        for (auto [v, w] : adj[u]) {
            if (v != fa) {
                if (!in[v]) {
                    dfs(v, u, res ^ w);
                } else {
                    a.push_back(res ^ w ^ xr[v]);
                }
            }
        }
    };
    dfs(0, -1, 0LL);

    i64 ans = xr[n - 1];
   
    n = a.size();
    int row = 0;
    for (int col = 63; col >= 0 and row < n; --col) {
        for (int i = row; i < n; ++i) {
            if (a[i] >> col & 1) {
                std::swap(a[row], a[i]);
                break;
            }
        }
        if (!(a[row] >> col & 1)) continue;
        for (int i = 0; i < n; ++i) {
            if (i == row) continue;
            if (a[i] >> col & 1) {
                a[i] ^= a[row];
            }
        }
        ++row;
    }
    for (int i = 0; i < row; ++i) {
        ans = std::max(ans, ans ^ a[i]);
    }
    std::cout << ans << "\n";
}

// 贪心法
#if 0 
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<std::pair<int, i64>>> adj(n);
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	i64 w;
    	std::cin >> u >> v >> w;
    	--u, --v;
    	adj[u].emplace_back(v, w);
    	adj[v].emplace_back(u, w);
    }
    std::vector<i64> p(64), xr(n);
    auto insert = [&](i64 x) {
    	for (int i = 63; i >= 0; --i) {
    		if (!(x >> i)) continue;
    		if (!p[i]) {
    			p[i] = x;
    			break;
    		} 
    		x ^= p[i];
    	}
    };
    // 答案必然是树上的一些环和一条主路径构成的
    std::vector<bool> in(n);
    std::function<void(int, int, i64)> dfs = [&](int u, int fa, i64 res) {
    	in[u] = true, xr[u] = res;
    	for (auto [v, w] : adj[u]) {
    		if (v != fa) {
    			if (!in[v]) {
    				dfs(v, u, res ^ w);
    			} else {
    				insert(res ^ w ^ xr[v]);
    			}
    		}
    	}
    };
    dfs(0, -1, 0LL);
    i64 ans = xr[n - 1];
    for (int i = 63; i >= 0; --i) {
    	ans = std::max(ans, ans ^ p[i]);
    }
    std::cout << ans << "\n";
}
#endif

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
