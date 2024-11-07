#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int &x : a) {
    	std::cin >> x;
    }
    for (auto &x : b) {
    	std::cin >> x;
    }
    std::cout << std::ranges::max(a) + std::ranges::max(b) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
