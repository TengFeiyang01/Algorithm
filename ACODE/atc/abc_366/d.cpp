#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector s(n + 1, std::vector(n + 1, std::vector(n + 1, 0)));
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		for (int k = 1; k <= n; ++k) {
    			std::cin >> s[i][j][k];
    			s[i][j][k] += s[i - 1][j][k] +
                  	s[i][j - 1][k] + s[i][j][k - 1] -
                  	s[i - 1][j - 1][k] - s[i - 1][j][k - 1] -
                  	s[i][j - 1][k - 1] + s[i - 1][j - 1][k - 1];
    		}
    	}
    }
    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
    	int lx, rx, ly, ry, lz, rz;
    	std::cin >> lx >> rx >> ly >> ry >> lz >> rz;
    	i64 ans = s[rx][ry][rz] - s[lx - 1][ry][rz] - s[rx][ly - 1][rz] -
          s[rx][ry][lz - 1] + s[lx - 1][ly - 1][rz] +
          s[lx - 1][ry][lz - 1] + s[rx][ly - 1][lz - 1] -
          s[lx - 1][ly - 1][lz - 1];
          std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
