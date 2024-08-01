#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n;
    std::cin >> n;
    std::set<std::string> st;
    for (int i = 0; i < n; ++i) {
    	std::string t;
    	std::cin >> t;
    	st.insert(t);
    }

    n = s.size();

    std::vector<int> dp(n + 1);
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= i; ++j) {
    		if (st.count(s.substr(j - 1, i - j + 1))) {
    			dp[i] = std::max(dp[i], dp[j - 2 >= 0 ? j - 2 : j - 1] + 1);
    		}
    	}
    	dp[i] = std::max(dp[i - 1], dp[i]);
    }
    std::cout << dp[n] << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
