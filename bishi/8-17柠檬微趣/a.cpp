#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;
    int ans = m + n;

    for (int i = -m; i < n; ++i) {
    	bool ok = true;
    	int tot;
    	if (i <= 0) {
    		tot = std::min(m + i, n);
    	} else {
    		tot = std::min(m, n - i);
    	}
    	for (int j = 0; j < m; ++j) {
    		if (i + j >= 0 and i + j < n and s[i + j] == '2' and t[j] == '2') {
    			ok = false;
    		}
    	}
    	if (ok) {
    		ans = std::min(ans, m + n - (tot));
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
