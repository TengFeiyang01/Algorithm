#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, ans = 0;
    std::cin >> n;
    std::string s;
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
    	int now = 0, mn = 0;
    	std::cin >> s;
    	for (auto c : s) {
    		if (c == '(') {
    			now++;
    		} else {
    			now--;
    			mn = std::min(mn, now);
    		}
    	}
    	if (mn == 0 || mn == now) {
    		if (cnt[-now] > 0) {
    			cnt[-now]--;
    			ans++;
    		} else {
    			cnt[now]++;
    		}
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
