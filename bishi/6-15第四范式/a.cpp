#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> prices[i];
    }

    int f0 = 0, f1 = INT_MIN;
    for (int p: prices) {
       	int new_f0 = std::max(f0, f1 + p);
        f1 = std::max(f1, f0 - p);
        f0 = new_f0;
    }

    std::cout << f0 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
