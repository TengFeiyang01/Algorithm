#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    int n;
    std::cin >> n >> s;
    std::vector<int> pre(n), suf(n + 1);
    std::string t("kira");
    for (int i = 0, j = 0; i < n; ++i) {
    	if (s[i] == t[j % 4]) {
    		j++;
    	}
    	pre[i] = j / 4 * 4;
    }
    
    t = "ikod";

    for (int i = n - 1, j = 0; i >= 0; --i) {
    	if (s[i] == t[j % 4]) {
    		j++;
    	}
    	suf[i] = j / 4 * 4;
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (pre[i] and suf[i + 1])
        	ans = std::max(ans, pre[i] + suf[i + 1]);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
