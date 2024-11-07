#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int ans = 0;
    std::string s;
    for (int i = 0; i < 12; ++i) {
    	std::cin >> s;
    	ans += s.size() == i + 1;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
