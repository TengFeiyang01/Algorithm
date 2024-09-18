#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n;
    std::string s;
    std::cin >> n >> s;
    int cnt = 0, ans = 0;
    s += "#";
    bool ok = 0;
    for (auto c : s) {
    	if (c == '#') {
            if (cnt <= 2) {
                ans += cnt;
            } else {
                std::cout << 2 << "\n";
                return;
            }
            cnt = 0;
    	} else {
    		cnt++;
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
