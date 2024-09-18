#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int x, ans = 0;
    while (n--) {
    	std::cin >> x;
    	ans = std::__gcd(x, ans);
    }
    std::cout << std::abs(ans) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
