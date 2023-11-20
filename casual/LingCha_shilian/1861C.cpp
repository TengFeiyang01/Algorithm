#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int unsortedsize = inf, sz = 0, sortedsize = 1; 

    for (auto c : s) {
    	if (c == '+') {
    		sz++;
    	} else if (c == '-') {
    		sz--;
    		if (sz < unsortedsize) {
    			unsortedsize = inf;
    		}
            if (sortedsize > sz) {
                sortedsize = sz;
            }
    	} else if (c == '1') {
            sortedsize = sz;
    		if (sz >= unsortedsize) {
                std::cout << "NO\n";
                return;
            }
    	} else if (c == '0') {
    		if (unsortedsize == inf) {
    			unsortedsize = sz;
    		} 

            if (sz <= sortedsize or sz < 2) {
                std::cout << "NO\n";
                return;
            }
    	}
    }
    std::cout << "YES\n";
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