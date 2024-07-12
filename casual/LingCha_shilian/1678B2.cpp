#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> n >> s;
    int ans = 0, seg = 0;
    char pre = ' ';
    for (int i = 0; i < n; i += 2) {
    	if (s[i] != s[i + 1]) {
    		ans++;
    	} else if (s[i] != pre) {
    		seg++;
    		pre = s[i];
    	}
    } 
    std::cout << ans << " " << std::max(seg, 1) << "\n";
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