#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(m), minL(n, inf), up(m);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		int last = a[j];
	    	std::cin >> a[j];
	    	if (a[j] < last) {
	    		up[j] = i;
	    	}
	    	minL[i] = std::min(minL[i], up[j]);
    	}
    }
    int q;
    std::cin >> q;
    while (q--) {
    	int l, r;
    	std::cin >> l >> r;
    	--r, --l;
    	if (minL[r] <= l) {
    		std::cout << "Yes\n";
    	} else {
    		std::cout << "No\n";
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
	solve();

    return 0;
}