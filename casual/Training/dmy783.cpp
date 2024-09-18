#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    const int B = 500;
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> large;
    std::vector<std::vector<i64>> p(n + 1), sum(B + 1, std::vector<i64>(B + 1));
    for (int i = 1; i <= q; ++i) {
    	int op, x, y;
    	std::cin >> op >> x;
    	if (op == 1) {
    		std::cin >> y;
    		int m = p[x].size();
    		if (m <= B) {
    			for (int j = 0; j < m; ++j) sum[m][j] -= p[x][j];
    		}
    		p[x].push_back(y);
    		++m;
    		if (m <= B) {
    			for (int j = 0; j < m; ++j) sum[m][j] += p[x][j];
    		} else if (m == B + 1) large.push_back(x);
    	} else {
    		i64 ans = 0;
    		for (int j = 1; j <= B; ++j) ans += sum[j][x % j];
    		for (auto y : large) {
    			ans += p[y][x % int(p[y].size())];
    		}
    		std::cout << ans << "\n";
    	}
    } 
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
