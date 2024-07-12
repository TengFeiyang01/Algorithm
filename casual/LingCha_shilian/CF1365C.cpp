#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> pos(n), cnt(n);
    
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	pos[x - 1] = i;
    }
    int res = 0, ans = 0;
    for (int j = 0; j < n; ++j) {
    	int x;
    	std::cin >> x;
    	cnt[(pos[x - 1] - j + n) % n]++;
    }
    std::cout << std::ranges::max(cnt);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
