#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int c[9];
	for (int i = 0; i < 9; ++i) {
		std::cin >> c[i];
	}
	int p[9];
	std::iota(p, p + 9, 0);
	int tot = 0, good = 0;
    std::vector<std::array<int, 3>> line {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };
    do {
    	tot++;
    	bool ok = true;
    	for (auto &l: line) {
    		std::sort(l.begin(), l.end(), [&](int i, int j){return p[i] < p[j];});
    		if (c[l[0]] == c[l[1]] && c[l[0]] != c[l[2]]) {
    			ok = false;
    		}
    	}
    	good += ok;
    } while (std::next_permutation(p, p + 9));
    double ans = 1.0 * good / tot;
    std::cout << std::fixed << std::setprecision(10) << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}