#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> m >> n;
    std::vector<int> a(n, inf);
    i64 s = 0;
    for (int i = 0; i < m; ++i) {
    	int pre = 0, cur = 0;
    	for (int j = 0; j < n; ++j) {
    		std::cin >> cur;
    		a[j] = std::min(a[j], cur - pre);
    		pre = cur;
    		if (i == m - 1) {
    			s += a[j];
    		}
    	}
    }
    std::cout << s << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
