#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    i64 ans = 0;
    int n = s.size();
    std::vector<int> l;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == '(') {
    		l.push_back(i);
    	} else {
    		if (l.empty()) continue;
    		ans += 2 * (l.back() + 1) * (n - i);
    		l.pop_back();
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
