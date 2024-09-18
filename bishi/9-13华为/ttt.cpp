#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q, x, y;
    std::cin >> n >> q >> x >> y;
    std::vector<int> next(n);
    int lg = 30;
    std::vector<std::vector<int>> to(n, std::vector<int>(lg + 1));
    for (int i = 0; i < n; ++i) {
    	std::cin >> to[i][0];
    	--to[i][0];
    }
    for (int j = 1; j <= lg; ++j) {
    	for (int i = 0; i < n; ++i) {
    		to[i][j] = to[to[i][j - 1]][j - 1];
    	}
    }
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::vector<int>> f(n, std::vector<int>(lg + 1));
    
    for (int i = 0; i < n; ++i) {
    	f[i][0] = (a[next[i]] > a[i]) ? x : y;
    }

    for (int j = 1; j <= lg; ++j) {
    	for (int i = 0; i < n; ++i) {
    		f[i][j] = std::max(f[i][j], f[i][j - 1] + f[to[i][j - 1]][j - 1]);
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
