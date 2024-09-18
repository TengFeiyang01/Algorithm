#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    int x = 1, y = 2;
    for (int i = 0; i < n; i++) {
    	for (int j = i % 2; j < n; j += 2) {
    		a[i][j] = x;
    		x += 2;
    	}
    }
    for (int i = 0; i < n; i++) {
    	for (int j = !(i % 2); j < n; j += 2) {
    		a[i][j] = y;
    		y += 2;
    	}
    }
    for (auto row : a) {
    	for (auto v : row) {
    		std::cout << v << " ";
    	}
    	std::cout << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
