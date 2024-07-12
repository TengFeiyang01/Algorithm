#include <bits/stdc++.h>

void solve() {
	int n, m;
	std::cin >> n >> m;
	int ans = n;
	std::set<int> st[n + 1];
	std::vector<int> vis(n + 1);
	while (m--) {
		int op, a, b;
		std::cin >> op;
		if (op == 1) {
			std::cin >> a >> b;
			st[a].insert(b);
			st[b].insert(a);
			if (!vis[a]) ans--;
			if (!vis[b]) ans--;
			vis[a]++;
			vis[b]++;
		} else {
			std::cin >> a;
			if (vis[a]) ans++;
			for (auto u : st[a]) {
				st[u].erase(a);
				vis[u]--;
				if (vis[u] == 0) ans++;
			}
			vis[a] = 0;
			st[a].clear();
		}
		std::cout << ans << "\n";
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
