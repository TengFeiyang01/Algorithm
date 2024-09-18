#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> R(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> R[i];
    }
    std::ranges::sort(R);
    for (int i = 1; i < n; ++i) {
    	R[i] += R[i - 1];
    }
    for (int i = 0; i < q; ++i) {
    	i64 x;
    	std::cin >> x;
    	std::cout << std::ranges::upper_bound(R, x) - R.begin() << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
