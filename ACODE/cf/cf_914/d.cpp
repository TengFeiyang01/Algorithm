#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
	std::vector<std::set<int>> pos(n + 1);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	pos[a[i]].insert(i);
    }
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    bool ok = true;
	for (int i = 0; i < n; ++i) {
		if (b[i] < a[i]) {
			ok = false;
			break;
		}
	}
	for (int val = 1; val <= n; ++val) {
		std::vector<bool> vis(n);
		for (auto x : pos[val]) {
			while (x < n and a[x] <= val and b[x] >= val) {
				vis[x] = true;
				a[x] = val;
				x++;
			}
		}
		for (auto x : pos[val]) {
			x--;
			while (x >= 0 and a[x] <= val and b[x] >= val) {
				vis[x] = true;
				a[x] = val;
				x--;
			}
		}
	}
	ok = a == b;


	if (!ok) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
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
