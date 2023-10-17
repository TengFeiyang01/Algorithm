#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n, s;
    std::cin >> n >> s;

    std::function<i64(i64, i64)> f = [&](i64 b, i64 n) ->i64 {
    	if (n < b) return n;
    	return f(b, n / b) + n % b;
    };
    if (n < s) {
    	std::cout << "-1\n";
    	return;
    }
    if (n == s) {
    	std::cout << n + 1 << "\n";
    	return;
    }
    i64 m = sqrt(n) + 1;
    for (int i = 2; i <= m; ++i) {
    	if (f(i, n) == s) {
    		std::cout << i << "\n";
    		return;
    	}
    }
    n -= s;
    i64 ans = 1e11;
    for (i64 p = 1; p * p <= n; ++p) {
    	if (n % p == 0) {
    		i64 b = n / p + 1;
    		i64 a0 = s - p;
    		i64 a1 = p;
    		if (b >= 2 and a0 >= 0 and a0 < b and a1 < b)
    			ans = std::min(ans, b);
    	}
    }
    if (ans == 1e11) std::cout << "-1\n";
    else std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
