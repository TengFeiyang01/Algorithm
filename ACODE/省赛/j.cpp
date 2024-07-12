#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    i64 s = 0;

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    }

    std::sort(a.begin(), a.end());
    if (a[0] == a.back()) {
    	std::cout << n << "\n";
    	return;
    }
    if (n == 2) {
    	std::cout << 1 << "\n";
    	return;
    }

    // for (int i = n - 1; i > 1; --i) {
    // 	int k = i;
    // 	if ( (k - s % k))
    // }
    std::cout << n - 1 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
