#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, x, m;
    std::cin >> n >> x >> m;
	
	int L = inf, R = -1;
	int ans = 0;
	for (int i = 0, l, r; i < m; ++i) {
		std::cin >> l >> r;
		if (l <= x and x <= r) {
			L = std::min(L, l);
			R = std::max(R, r);
		}
		if (L != inf and R != -1) {
			if (r >= L and l <= L) {
				L = std::min(L, l);
			}
			if (l <= R and r >= R) {
				R = std::max(r, R);
			}
		}
	}    
	if (R == -1) {
		std::cout << 1 << "\n";
		return;
	}
	std::cout << R - L + 1 << "\n";
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
