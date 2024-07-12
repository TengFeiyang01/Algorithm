#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int ans = 0;
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;

    int i = 0;
    while (i < n) {
    	if (s[i] == 'W') {
    		i++;
    	} else {
    		i += k;
    		ans++;
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}