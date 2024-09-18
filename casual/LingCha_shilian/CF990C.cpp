#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    i64 ans = 0;
    std::map<int, i64> cnt;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
    	int c = 0, mn = 0;
    	std::cin >> s;
    	for (auto ch : s) {
    		if (ch == '(') {
    			c++;
    		} else {
    			c--;
    			mn = std::min(mn, c);
    		}
    	}
    	if (mn == 0 || mn == c) {
    		if (c == 0) {
    			ans += cnt[c] * 2 + 1;
    		} else {
    			ans += cnt[-c];
    		}
    		cnt[c]++;
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
