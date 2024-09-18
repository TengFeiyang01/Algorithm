#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (!b) {
        x = 1;
    	y = 0;
    	return a;
  	}
  	// i64 d = exgcd(b, a % b, x, y);
  	// i64 tmp = y;
  	// y = x - (a / b) * y;
 	// x = tmp;
  	i64 d = exgcd(b, a % b, y, x);
  	y -= (a / b) * x;
  	return d;
}

void solve() {
    i64 a, b, x, y, m;
    std::cin >> a >> b >> m;
    i64 d = exgcd(a, b, x, y);
    // y = -y;
    if (m % d) {
        std::cout << "-1\n";
        return;
    }

    a /= d;
    b /= d;
    m /= d;
    // a 和 b 是互质
    // x = x * m, y = y * m;   
    // 此时由 ax+by=1 都乘m是原方程
    i64 xx = x * (m % b) % b;
    if (xx < 0) xx += b;
    i64 yy = (m - a * xx) / b;
    if (yy < 0) {
        std::cout << "-1\n";
        return;
    }
    std::cout << xx << " " << yy << "\n";
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
