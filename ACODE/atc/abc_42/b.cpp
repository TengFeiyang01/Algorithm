#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, l;
    std::cin >> n >> l;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> s[i];
    }
    std::ranges::sort(s);
    for (auto x : s) {
    	std::cout << x;
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
