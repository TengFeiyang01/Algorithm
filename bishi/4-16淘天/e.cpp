#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> pos;

    for (int i = 0; i < n; ++i) {
    	if (s[i] == '1') {
    		pos.push_back(i);
    	}
    }
    int m = pos.size();

    i64 ans = 0;
    int p = m / 2;

    for (int i = 0, k = 1; i < p; ++i, ++k) {
    	ans += pos[p] - pos[i] - k; 
    }
    for (int k = 1, i = p + 1; i < m; ++i, ++k) {
    	ans += pos[i] - pos[p] - k;
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
