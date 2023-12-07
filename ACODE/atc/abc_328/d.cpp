#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    std::string ans = "";
    for (auto c : s) {
    	ans += c;
    	int p = ans.size();
    	if (p >= 3 and ans.substr(p - 3, 3) == "ABC") {
    		ans.pop_back();
    		ans.pop_back();
    		ans.pop_back();
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
