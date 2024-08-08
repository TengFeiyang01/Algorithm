#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::map<std::string, int> cnt;
    std::string ans;
    int mx = 0;
    for (int i = 0; i + k - 1 < n; ++i) {
    	if (++cnt[s.substr(i, k)] > mx) {
    		mx = cnt[s.substr(i, k)];
    		ans = s.substr(i, k);
    	} else if (cnt[s.substr(i, k)] == mx) {
    		ans = std::min(ans, s.substr(i, k));
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
