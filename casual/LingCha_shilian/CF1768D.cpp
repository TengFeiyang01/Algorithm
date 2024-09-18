#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> p(n), id(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> p[i];
    	--p[i];
    }
    int ans = n + 1;
    for (int v = 0; v < n; ++v) {
        int i = id[v];
        if (i > 0) continue;
        while (id[v] == 0) {
            id[v] = ans;
            v = p[v];
        }
        ans--;
    }
    for (int i = 1; i < n; ++i) {
    	if (id[i] == id[i - 1]) {
    		ans -= 2;
    		break;
    	}
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
