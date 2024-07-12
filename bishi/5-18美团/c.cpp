#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    std::unordered_set<char> st{'a', 'e', 'i', 'o', 'u'};
    std::string t;
    for (auto c : s) {
    	if (!st.count(c)) {
    		t += c;
    	}
    }

    std::cout << t << "\n";
    std::vector<std::vector<int>> pos(26);
    s = t;
    int n = s.size();
    std::vector<std::array<int, 26>> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j < 26; ++j) {
    		pre[i][j] += pre[i - 1][j];
    	}
    	pre[i][s[i - 1] - 'a']++;
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
    	for (int j = 0; j < 26; ++j) {
    		for (int k = 0; k < 26; ++k) {
    			if (pre[i - 1][j]) {
    				ans++;
    			}
    			if (pre[i - 1][j] and pre[n][k] - pre[i][k]) {
    				ans++;
    			}
    		}
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}