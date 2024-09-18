#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> b(n), c(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> c[i];
    }

    int ans = 1;
    for (int i = 0; i < n; ++i) {
    	bool fixB = (i == 0 || b[i] > b[i - 1]);
    	bool fixC = (i == n - 1 || c[i] > c[i + 1]);
    	if ((fixB && b[i] > c[i]) || (fixC && c[i] > b[i])) {
    		std::cout << "0\n";
    		return;
    	}
    	if (!fixB && !fixC) {
    		ans = 1LL * ans * std::min(b[i], c[i]) % (1000000007);
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