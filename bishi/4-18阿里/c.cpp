#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

// 思路：同一个主对角线的下标之和相等，
// 副对角线下标之差相等 直接哈希表计数即可

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::map<i64, int> rol, col;
    i64 ans = 0, res = 0;
    for (int i = 0; i < m; ++i) {
    	i64 x, y;
    	std::cin >> x >> y;
    	if (++rol[x + y] == 1) {
    		ans++;
    	}
    	if (++col[x - y] == 1) {
    		res++;
    	}
    }
    std::cout << ans << " " << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
