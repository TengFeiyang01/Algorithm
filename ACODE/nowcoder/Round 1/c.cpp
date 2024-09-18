#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::string s;
    std::cin >> s;
    i64 ans = 0;
    i64 res = 0;
    int n = s.size();
    int cnt0 = 0;
    int cnt1 = 0;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == '1') {
    		ans += abs(2 * cnt1 - i);
    		cnt1++;
    	} else {
    		res += abs(2 * cnt0 - i);
    		cnt0++;
    	}
    }
    if (n % 2 == 0)
        std::cout << std::min(ans, res) << "\n";
    else {
        if (cnt0 > cnt1) {
            std::cout << res << "\n";
        } else {
            std::cout << ans << "\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}