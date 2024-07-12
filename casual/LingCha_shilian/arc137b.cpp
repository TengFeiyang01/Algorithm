#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int inc = 0, dec = 0, maxinc = 0, maxdec = 0;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	inc = std::max(inc, 0) + 1 - 2 * x;
    	maxinc = std::max(maxinc, inc);
    	dec = std::max(dec, 0) + 2 * x - 1;
    	maxdec = std::max(maxdec, dec);
    }
    std::cout << maxinc + 1 + maxdec << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}