#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::function<i64(i64, i64)> f = [&](i64 s, i64 k) -> i64 {
    	if (k == 0) return 0;
    	i64 ans = s * k;
    	if (s % 10 == 0) {
            //pass
        } else if (s % 10 != 2) {
    		ans = std::max(ans, f(s + s % 10, k - 1));
    	} else {
    		std::array<int, 5> h = {0, 2, 6, 14, 20};
    		auto g = [&](i64 n) {
    			return (s + n / 4 * h[4] + h[n % 4]) * (k - n);
    		};
    		i64 m = std::max((5 * k - s) / 10, i64(0));
    		for (i64 i = -100; i <= 100; ++i) {
    			if (i + m >= 0 and i + m <= k) {
    				ans = std::max(ans, g(i + m));
    			}
    		}
    	}
        return ans;
    };

    i64 s, k;
    std::cin >> s >> k;
    std::cout << f(s, k) << "\n";
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
