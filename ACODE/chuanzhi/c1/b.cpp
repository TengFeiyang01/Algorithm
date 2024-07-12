#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

constexpr int mod = 1000000007;

void solve() {
    // std::string s;
    // std::cin >> s;
    // int n = s.size();
    // if (n == 1) {
    // 	std::cout << "0\n";
    // 	return;
    // }
    // std::vector<i64> dp(2);
    // dp[0] = 25;

    // for (int i = 0; i < n; ++i) {
    // 	std::vector<i64> ndp(2);
    // 	ndp[0] = dp[]
    // }
    std::string s = "cdx";
    int ans = 0;
    for (auto a = 'a'; a <= 'z'; ++a) {
    	for (auto b = 'a'; b <= 'z'; ++b) {
    		for (auto c = 'a'; c <= 'z'; ++c) {
    			if (a != s[0] and b != s[1] and c != s[2]) {
    				if (!(a - s[0] == b - s[1] and a - s[0] == c - s[2] and b - s[1] == c - s[2])) {
    					ans++;
    				}
    			}
    		}
    	}
    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
