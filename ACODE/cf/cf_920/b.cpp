#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == '1' and t[i] == '0') {
    		cnt1++;
    	} else if (t[i] == '1' and s[i] == '0') {
    		cnt2++;
    	}
    }
    std::cout << std::max(cnt1, cnt2) << "\n";
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
