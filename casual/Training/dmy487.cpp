#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
    if (!b) {
        x = 1;
    	y = 0;
    	return a;
  	}
  	i64 d = exgcd(b, a % b, x, y);
  	int tmp = y;
  	y = x - (a / b) * y;
 	x = tmp;
  	// i64 d = exgcd(b, a % b, y, x);
  	// y -= (a / b) * x;
  	return d;
}

void solve() {
    i64 a, b, x, y;
    std::cin >> a >> b;
    i64 d = exgcd(a, b, x, y);
    y = -y;
    while (x < 0 or y < 0) x += b / d, y += a / d;
    std::cout << x << " " << y << "\n";
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
