#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::vector<int> cnt(26);
    int n, k;
    std::string s, t;
    std::cin >> n >> k >> s >> t;
    for (int i = 0; i < n; ++i) {
    	if (n - k <= i && i < k && s[i] != t[i]) {
    		std::cout << "NO\n";
    		return;
    	}
    	cnt[s[i] - 'a']++;
    	cnt[t[i] - 'a']--;
    }
    if (cnt == std::vector<int>(26, 0)) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
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
