#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1e5 + 10;
i64 f[N], g[N];

i64 qpow(i64 x, i64 y, int mod) {
    i64 res = 1;
    for (; y; y /= 2, x = x * x % mod)
        if (y & 1)
            res = res * x % mod;
    return res;
}

void init(i64 p) {
	f[0] = g[0] = 1LL;
	for (int i = 1; i <= p; ++i) {
		f[i] = f[i - 1] * i % p;
		g[i] = g[i - 1] * qpow(i, p - 2, p) % p;
	}
}

i64 get(int n, int m, i64 p) {
	if (m > n) return 0;
	return f[n] * g[m] % p * g[n - m] % p;
}

i64 lucas(i64 n, i64 m, i64 p) {
	if (m == 0) return 1;
	return lucas(n / p, m / p, p) * get(n % p, m % p, p) % p;
}

void solve() {
    i64 n, m, p;
    std::cin >> n >> m >> p;
    init(p);
    std::cout << (lucas(n + m, n, p) % p + p) % p << "\n";
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
