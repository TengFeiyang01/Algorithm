#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    int tot = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	tot += a[i];
    	b[i] = a[i];
    	if (i) {
    		a[i] += a[i - 1];
    	}
    }
    for (int i = 0; i < n; ++i) {
    	if (a[i] - b[i] == tot - a[i]) {
    		std::cout << i + 1 << "\n";
    		return;
    	}
    }
    std::cout << "-1\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
