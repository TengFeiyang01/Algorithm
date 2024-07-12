#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n;
    m = 4 * n;
    std::vector<std::string> s;
    for (int i = 0; i < n; ++i) {
    	std::string t = "";
    	t = std::string(n - i, '.') + std::string(2 * n + 2 * i, '*') + std::string(n - i, '.');
    	s.push_back(t);
    }
    for (int i = 0; i < n; ++i) {
    	s.push_back(std::string(n, '*') + std::string(2 * n, '.') + std::string(n, '*'));
    }
    for (auto c : s) {
    	std::cout << c << "\n";
    }
    for (auto c : std::views::reverse(s)) {
    	std::cout << c << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
