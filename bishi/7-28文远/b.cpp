#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, m, x1, y1, x2, y2;
    std::cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    
    // 计算两个针头移动的绝对距离
    i64 x = abs(x1 - x2);
    i64 y = abs(y1 - y2);

    i64 s1 = n - x, t1 = m - y;
    i64 s2 = x + 1, t2 = y + 1;	

    if (x == 0) {
    	s1 = n;
    	s2 = 1;
    }
    if (y == 0) {
    	t1 = m;
    	t2 = 1;
    }


    std::cout << n * m - 2 * (s1 * t1) +
     std::max(0ll, std::max(0LL, s1 - s2 + 1) * std::max(0LL, t1 - t2 + 1)) << "\n";
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
