#include <bits/stdc++.h>

const int inf = 0x5f3f3f3f;
using i64 = long long;

void solve() {
	int ans = 0, ans1 = 0, ans2 = 0;
	int t = 5;
	int n = t * t, m = t, k = 6;
    for (int i = 0; i < 1LL << n; ++i) {
    	int cnt = 0;
    	for (int j = 0; j < n; ++j) cnt += i >> j & 1;
    	if (cnt != 6) continue;
    	int a[10][10];
    	for (int j = 0; j < n; ++j) {
    		a[j / m][j % m] = (i >> j & 1);
    	}
    	std::set<int> st;
    	for (int p = 0; p < m; ++p) {
    		int x = 0;
    		for (int q = 0; q < m; ++q) {
    			x ^= a[p][q];
    		}
    		st.insert(x);
    	}
    	for (int p = 0; p < m; ++p) {
    		int x = 0;
    		for (int q = 0; q < m; ++q) {
    			x ^= a[q][p];
    		}
    		st.insert(x);
    	}
    	if (st.size() == 1) {
    		if (*st.begin() == 0) {
    			ans1++;
    		} else {
    			ans2++;
    		}
	    	for (int p = 0; p < m; ++p) {
	    		for (int q = 0; q < m; ++q) {
	    			std::cout << a[p][q];
	    		}
	    		std::cout << "\n";
	    	}
	    	std::cout << "\n";
	    	ans++;
    	}
    }
    std::cout << ans << " " << ans1 << " " << ans2  << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
