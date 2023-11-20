#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int ans = 0, now = 0;
    for (auto c : s) {
    	if (c == '(') {
    		now++;
    	} else {
    		if (now > 0) {
	    		ans += 2;
    			now--;
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