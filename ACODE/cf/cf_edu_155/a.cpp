#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int a, b;
    std::cin >> a >> b;
    
    int ok = 0;

    for (int i = 1; i < n; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	if (y >= b and x >= a) {
            ok = 1;
        }
    }
    std::cout << (ok ? -1 : a) << "\n";
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