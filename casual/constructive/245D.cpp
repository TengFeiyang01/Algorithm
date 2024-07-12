#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector b(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
    	int x = 0;
    	for (int j = 0; j < n; ++j) {
    		std::cin >> b[i][j];
    		if (j != i) {
    			x |= b[i][j];
    		}
    	}
    	std::cout << x << " ";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
