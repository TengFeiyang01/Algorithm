#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k, t;
    std::cin >> n >> k >> t;
    if (t + 1 > k) {
    	std::cout << "-1\n";
    } else {
        int s = n - t - 1;
        k -= t + 1;
        std::string ans(t + 1, '1');
        while (s) {
            if (k) {
                ans += "01";
                k--;
                s -= 2;
                if (s < 0) {
                    std::cout << "-1\n";
                    return;
                }
            } else {
                ans += "0";
                s--;
            }
        }
        std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
