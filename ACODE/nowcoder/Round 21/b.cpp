#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector s(n, std::string(m, '.'));
    auto gao = [&](int x, int y, char c) {
    	int dir[][2] = {{0, 0}, {0, 1}, {0, 2}, {1, 0}, {2, 0}, {-1, 0}, {-2, 0}, {0, -1}, {0, -2}};
    	for (int i = 0; i < 9; ++i) {
    		int nx = x + dir[i][0], ny = y  + dir[i][1];
    		if (0 <= nx and nx < n and 0 <= ny and ny < m) {
    			s[nx][ny] = c;
    		}
    	}
    };
    for (int i = 0; i < k; ++i) {
    	int x, y;
    	char c;
    	std::cin >> x >> y >> c;
        --x, --y;
    	gao(x, y, c);
    }
    for (int i = 0; i < n; ++i) {
    	std::cout << s[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
