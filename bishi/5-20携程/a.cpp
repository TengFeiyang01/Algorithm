#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    int p;
    std::cin >> s >> p;
    i64 ans = 0;
    for (auto c : s) {
    	int x = c - '0';
    	if (x % 2) {
    		ans = ans * 10 + x;
    		ans %= p;
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
