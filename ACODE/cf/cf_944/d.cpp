#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size(), cnt = 0, f = 0;
    char pre = ' ';
    for (int i = 0; i < n; ++i) {
    	if (s[i] != pre) {
    		cnt++;
    		if (s[i] == '1' and pre == '0') {
    			f = 1;
    		}
    	}
		pre = s[i];    	
    }
    std::cout << cnt - f << "\n";
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
