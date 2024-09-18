#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int M = 1000100;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 2);
    std::vector<std::vector<int>> pos(M);
    int ans = 0;

    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	pos[a[i]].push_back(i);
    }
    for (int i = 1; i <= n + 1; ++i) ans += a[i] != a[i - 1];
   
    for (int i = 0; i < m; ++i) {
    	int op;
    	std::cin >> op;
    	if (op == 1) {
    		int x, y;
    		std::cin >> x >> y;
    		if (x == y) continue;
    		if (pos[x].size() > pos[y].size()) {
    			pos[x].swap(pos[y]);
    		}
    		if (pos[y].empty()) continue;
    		auto modify = [&](int p, int col) {
    			ans -= (a[p] != a[p - 1]) + (a[p] != a[p + 1]);
    			a[p] = col;
    			ans += (a[p] != a[p - 1]) + (a[p] != a[p + 1]);
    		};

    		int col = a[pos[y][0]];
    		for (int p : pos[x]) {
    			modify(p, col);
    			pos[y].push_back(p);
    		}
    		pos[x].clear();
     	} else {
    		std::cout << ans - 1 << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}