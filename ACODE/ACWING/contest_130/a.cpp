#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
 	int a, b, c;
 	std::cin >> a >> b >> c;
 	std::cout << std::max({a, b, c}) << " " << std::min({a, b, c});   
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
