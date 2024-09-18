#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    if (k >= 3E5) {
    	std::cout << "-1\n";
    } else {
    	i64 sum = (1 + k) * k / 2;
    	if (n < sum) {
    		std::cout << "-1\n";
    		return;
    	}
        //仅需枚举n的因子即可
        std::vector<i64> g;
        for (i64 i = 1; i <= std::sqrt(n); ++i) {
            if (n % i == 0) {
                g.push_back(i);
                if (n / i != i) {
                    g.push_back(n / i);
                }
            }
        }
        std::sort(g.begin(), g.end(), std::greater<i64>());
        for (auto x : g) {
            if (n / x >= sum) {
                for (int i = 1; i < k; ++i) {
                    std::cout << i * x << " ";
                }
                std::cout << n - x * (k - 1) * k / 2;
                break;
            }
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}