#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size(), ans = n;
    for (int i = 1; i < 1 << n; ++i) {
    	int now = 0, cnt = n, ok = true;
    	for (int j = 0; j < n; ++j) {
    		if (i >> j & 1) {
                if (cnt == n and s[j] == '0') {
                    ok = false;
                }
    			cnt--;
    			now = now * 10 + (s[j] - '0');
    		}
    	}
    	int p = sqrt(now);
    	if (p * p == now and ok) {
    		ans = std::min(ans, cnt);
    	}
    }
    if (ans == n) {
    	ans = -1;
    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
