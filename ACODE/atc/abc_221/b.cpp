#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int x = -1, y = -1;
    for (int i = 0; i < s.size(); ++i) {
    	if (s[i] != t[i]) {
    		if (x == -1) {
    			x = i;
    		} else {
    			y = i;
    		}
    	}
    }
    if (x != -1 and y != -1 and x + 1 == y)    
        std::swap(s[x], s[y]);
    if (s == t) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
