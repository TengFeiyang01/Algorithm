#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string s;
    std::cin >> s;
    n = s.size();
    int ans = n;
    
    int in0 = 0, out1 = std::ranges::count(s, '1');
    for (int l = 0, r = 0; r < n; ++r) {
    	if (s[r] == '0') {
    		in0++;
    	} else {
    		out1--;
    	}
    	while (in0 > out1) {
    		if (s[l] == '0') {
    			in0--;
    		} else {
    			out1++;
    		}
    		l += 1;
    	}
    	ans = std::min(ans, std::max(in0, out1));
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