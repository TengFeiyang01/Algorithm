#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int i = 0, j = 0; i < m; ++i) {
    	if (s[j] == t[i]) {
    		std::cout << i + 1 << " ";
    		j++;
    	}
    	if (j == n) {
    		break;
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
