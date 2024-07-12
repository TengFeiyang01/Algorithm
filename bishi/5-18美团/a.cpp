#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, x;
    std::cin >> n >> x;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (a[i] != -1) {
    		x -= a[i];
    	}
    }

    for (int i = 0; i < n; ++i) {
    	if (a[i] == -1) {
    		a[i] = x;
    	}
    	std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
