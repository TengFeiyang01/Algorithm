#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    i64 pos;
    std::cin >> s >> pos;

    pos--;
    int x, y;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        int len = n - i;
        if (pos < len) {
            x = i;
            y = pos;
            break;
        } 
        pos -= len;
    }

    std::string stk;
    for (int i = 0; i < n; ++i) {
    	while (x and stk.size() and stk.back() > s[i]) {
    		stk.pop_back();
            --x;
    	}
        stk += s[i];
    }
    std::cout << stk[pos];
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