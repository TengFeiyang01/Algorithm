#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<std::array<i64, 2>> op(m);
    for (int i = 0; i < m; ++i) {
    	std::cin >> op[i][1] >> op[i][0];
    	op[i][0] = -op[i][0];
    }
    std::sort(op.begin(), op.end());
    i64 ans = 0, cnt = n;
    std::vector<i64> b;
    for (int i = 0; i < m; ++i) {
    	if (cnt >= op[i][1]) {
    		cnt -= op[i][1];
    		while (op[i][1]) {
    			b.push_back(-op[i][0]);
    			op[i][1]--;
    		}
    	} else {
    		while (cnt) {
    			cnt--;
    			b.push_back(-op[i][0]);
    		}
    	}
    }
    while (b.size() < n) {
    	b.push_back(0);
    }
    std::sort(a.begin(), a.end());
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
    	ans += std::max(a[i], b[i]);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
