#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, ans = 0;
    std::string s;
    std::cin >> n >> s;
    std::map<int, int> cnt;
    for (auto x : s) {
    	int c = x - 'A' + 1;
    	cnt[c]++;
    	if (cnt[c] == c) {
    		ans++;
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
