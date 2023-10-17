#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    int ok = 0;
    std::string s, t;
    std::cin >> n >> m >> s >> t;
    if (s.find(t) != -1) {
    	std::cout << 0 << "\n";
    	return;
    }
    for (int i = 1; i <= 10; ++i) {
    	s += s;
    	if (s.size() >= m and s.find(t) != -1) {
    		std::cout << i << "\n";
    		ok = 1;
    		return;
    	}
    }
    if (!ok) {
    	std::cout << "-1\n";
    }
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