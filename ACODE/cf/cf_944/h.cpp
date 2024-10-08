#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

struct TwoSat {
    int n;
    std::vector<std::vector<int>> e;
    std::vector<bool> ans;
    TwoSat(int n) : n(n), e(2 * n), ans(n) {}
    void addClause(int u, bool f, int v, bool g) {
        e[2 * u + !f].push_back(2 * v + g);
        e[2 * v + !g].push_back(2 * u + f);
    }
    bool satisfiable() {
        std::vector<int> id(2 * n, -1), dfn(2 * n, -1), low(2 * n, -1);
        std::vector<int> stk;
        int now = 0, cnt = 0;
        std::function<void(int)> tarjan = [&](int u) {
            stk.push_back(u);
            dfn[u] = low[u] = now++;
            for (auto v : e[u]) {
                if (dfn[v] == -1) {
                    tarjan(v);
                    low[u] = std::min(low[u], low[v]);
                } else if (id[v] == -1) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
            if (dfn[u] == low[u]) {
                int v;
                do {
                    v = stk.back();
                    stk.pop_back();
                    id[v] = cnt;
                } while (v != u);
                ++cnt;
            }
        };
        for (int i = 0; i < 2 * n; ++i) if (dfn[i] == -1) tarjan(i);
        for (int i = 0; i < n; ++i) {
            if (id[2 * i] == id[2 * i + 1]) return false;
            ans[i] = id[2 * i] > id[2 * i + 1];
        }
        return true;
    }
    std::vector<bool> answer() { return ans; }
};


void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(3, std::vector<int>(n));
    for (int i = 0; i < 3; ++i) {
    	for (int j = 0; j < n; ++j) {
    		std::cin >> g[i][j];
    	}
    }

    TwoSat ts(n);

    auto add = [&](int x, int y) -> void {
        bool f = 0, g = 0;
        if (x < 0) f = 1, x = -x;
        if (y < 0) g = 1, y = -y;
        --x, --y;
        ts.addClause(x, f, y, g);
    };

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < 3; ++j) {
    		for (int k = j + 1; k < 3; ++k) {
    			add(g[j][i], g[k][i]);
    		}
    	}
    }

    if (ts.satisfiable()) {
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
