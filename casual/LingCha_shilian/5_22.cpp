#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
    std::vector<std::unordered_map<int, int>> fa(m);

    std::function<int(int, int)> find = [&](int c, int x) ->int {
        int f;
        if (!fa[c].count(x)) {
            fa[c][x] = x;
            f = x;
        }
        f = fa[c][x];
        if (f != x) {
            fa[c][x] = find(c, f);
            return fa[c][x];
        }
        return x;
    };  

    for (int i = 0; i < m; ++i) {
    	int u, v, c;
    	std::cin >> u >> v >> c;
    	--c;
        u = find(c, u);
        v = find(c, v);
        fa[c][u] = v;
    }
    int q;
    std::cin >> q;
    while (q--) {
        int x, y, cnt = 0;
        std::cin >> x >> y;
        for (int i = 0; i < m; ++i) {
            if (find(i, x) == find(i, y)) {
                cnt++;
            }
        }
        std::cout << cnt << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
