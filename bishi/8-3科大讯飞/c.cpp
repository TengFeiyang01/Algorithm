#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 1; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x, --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    std::vector<int> up(n, 1), down(n, 1);
    std::function<void(int, int)> dfs1 = [&](int u, int fa) {
        for (int v : adj[u]) {
            if (v == fa) continue;
            dfs1(v, u);
            if (a[v] > a[u]) {
                up[u] = std::max(up[u], up[v] + 1);
            }
            if (a[v] < a[u]) {
                down[u] = std::max(down[u], down[v] + 1);
            }
        }
    };

    std::function<void(int, int)> reroot = [&](int u, int fa) {
        for (auto v : adj[u]) {
            if (v == fa) continue;

            // 保存原始值
            int original_up_u = up[u], original_down_u = down[u];
            int original_up_v = up[v], original_down_v = down[v];

            // 从u到v的路径更新
            if (a[v] >= a[u]) {
                up[u] = std::max(up[u], up[v] + 1);
                up[v] = std::max(up[v], original_up_u + 1);
            }
            if (a[v] <= a[u]) {
                down[u] = std::max(down[u], down[v] + 1);
                down[v] = std::max(down[v], original_down_u + 1);
            }

            reroot(v, u);

            // 恢复原始值
            up[u] = original_up_u;
            down[u] = original_down_u;
            up[v] = original_up_v;
            down[v] = original_down_v;
        }
    };

    dfs1(0, -1);
    reroot(0, -1);

    int longest_inc_dec = 0;
    for (int i = 0; i < n; ++i) {
        longest_inc_dec = std::max(longest_inc_dec, up[i] + down[i] - 1);
    }

    std::cout << "Longest increasing/decreasing chain length: " << longest_inc_dec << std::endl;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
