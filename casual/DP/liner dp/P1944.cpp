#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    s = " " + s;
    int n = s.size();
    std::vector<int> dp(n + 1);
    int st = -1, ans = 0;
    for (int i = 2; i <= n; ++i) {
    	if (s[i] == '(' or s[i] == '[') continue;
    	else {
    		if (s[i] == ')' and s[i - dp[i - 1] - 1] == '(' or
    			s[i] == ']' and s[i - dp[i - 1] - 1] == '[') {
    			dp[i] = dp[i - dp[i - 1] - 2] + dp[i - 1] + 2;
    			if (dp[i] > ans) {
    				ans = dp[i];
                    st = i - ans + 1;
    			}
    		}
    	}
    }
    std::cout << s.substr(st, ans);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
