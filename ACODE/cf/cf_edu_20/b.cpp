#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<int> suf(n, 2 * n + 1);
    for (int i = n - 1; i >= 0; --i) {
    	if (a[i] == 0) {
    		suf[i] = i;
    	} else {
            if (i + 1 < n)
        		suf[i] = suf[i + 1];
    	}
    }
    int pre = -(n + 1);
    for (int i = 0; i < n; ++i) {
    	if (a[i] == 0) {
    		pre = i;
    		std::cout << "0 ";
    	} else {
    		std::cout << std::min(i - pre, suf[i] - i) << " ";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}