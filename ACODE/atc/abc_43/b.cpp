#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    std::string ans;
    for (auto c : s) {
    	if (c == 'B') {
    		if (ans.size()) {
    			ans.pop_back();
    		}
    	} else {
    		ans += c;
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
