#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

i64 exgcd(i64 a, i64 b, i64& x, i64& y) {	
	if (!b) {
		x = 1;
        y = 0;
		return a;
	}
	i64 d = exgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return d;
}

i64 EXCRT(std::vector<i64> &m, std::vector<i64> &r) {
    i64 m1, m2, r1, r2, p, q;
    m1 = m[0], r1 = r[0];
    for (int i = 1; i < m.size(); ++i) {
        m2 = m[i], r2 = r[i];
        i64 d = exgcd(m1, m2, p, q);
        if ((r2 - r1) % d) return -1;
        m2 /= d;
        p = p % m2 * (r2 - r1) / d % m2;  // 特解
        p = (p % m2 + m2) % m2;
        r1 = m1 * p + r1;
        m1 = m1 * m2;
    }
    return (r1 % m1 + m1) % m1;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> r(n), m(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> r[i] >> m[i];
    }
    std::cout << EXCRT(m, r) << "\n";
}

// 模数互质
/*void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> r(n), m(n);
    i64 M = 1;
    for (int i = 0; i < n; ++i) {
    	std::cin >> r[i] >> m[i];
        M = std::lcm(M, m[i]);
    }

    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        i64 c = M / m[i], x, y;
    	exgcd(c, m[i], x, y);
    	ans = (ans + r[i] * c * x % M) % M;
    }
    if (ans < 0) ans += M;
    std::cout << ans << "\n";
}*/

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
	