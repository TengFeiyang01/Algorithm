#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::string s;
    std::cin >> n >> k >> s;
    if (k % 2 == 0) {
    	std::sort(s.begin(), s.end());
    	std::cout << s << "\n";
    } else {
    	std::string t[2];
    	for (int i = 0; i < n; ++i) {
    		t[i % 2] += s[i];
    	}
    	std::sort(t[0].begin(), t[0].end());
    	std::sort(t[1].begin(), t[1].end());
    	for (int i = 0; i < t[0].size(); ++i) {
    		std::cout << t[0][i];
    		if (i < t[1].size()) std::cout << t[1][i];
    	}
    	std::cout << "\n";
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