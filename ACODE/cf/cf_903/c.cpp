#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> s[i];
    }
    i64 ans = 0;
    for (int i = 0; i < (n + 1) / 2; ++i) {
    	for (int j = i; j < n - i - 1; ++j) {
    		std::vector<char> tmp{
    			s[i][j], s[j][n - i - 1], s[n - 1 - i][n - 1 - j], s[n - 1 - j][i]
    		};
            std::sort(tmp.begin(), tmp.end());
            for (int k = 0; k < 4; ++k) {
                ans += (tmp[3] - tmp[k]) % 26;
            }
    	}
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