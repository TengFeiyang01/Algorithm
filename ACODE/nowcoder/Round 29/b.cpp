#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s, t;
    std::cin >> n >> s >> t;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == 'Y' and t[i] == 'Y') {
    		ans += 3;
    	} else if (s[i] == 'Y' or t[i] == 'Y') {
    		ans += 2;
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
