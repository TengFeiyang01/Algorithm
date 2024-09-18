#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    // 1可以出现在任何位置 去除1后 将1放在第一个2之前即可
    std::string s1(std::ranges::count(s, '1'), '1');
    std::string ans;
    for (auto c : s) {
    	if (c != '1') {
    		ans += c;
    	}
    }
    int idx = ans.find('2');

    if (idx >= 0) {
    	std::cout << ans.substr(0, idx) + s1 + ans.substr(idx);
    } else {
    	std::cout << ans + s1 << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
