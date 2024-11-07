#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> m >> n;
    // n是抽屉数 m是位置
    std::vector<i64> a(n*3+1), s(n*3+1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
    	a[n + i] = a[i] + m;
    }
    for (int i = 1; i <= n; ++i) {
    	a[2*n + i] = a[i] + 2 * m;
    }
    for (int i = 1; i <= 3 * n; ++i) {
    	s[i] = s[i - 1] + a[i];
    }

    i64 ans = 1e18;
    std::sort(a.begin(), a.end());
	
	i64 d = m / 2, pos = a[1];

	for (int i = n + 1; i <= 2 * n; ++i) {
		int l = std::lower_bound(a.begin(), a.end(), a[i] - d) - a.begin() + 1;
		i64 r = l + n - 1;
		// std::cout << "--" << l << " " << i << " " << r << "--\n";
		// for (int z = l; z <= r; ++z) {
		// 	std::cout << a[z] << " \n"[z == r];
		// }
		// std::cout << "s[r]" << s[r] << " " << s[i] << "\n";
		i64 cur = a[i] * (i - l) - (s[i - 1] - s[l - 1]) + (s[r] - s[i] - a[i] * (r - i));
		std::cout << a[i] << " " << cur << "\n";
		if (cur < ans) {
			ans = cur;
			pos = a[i] - m;
		}
	}    
	std::cout << pos << "\n";
}

// 1 2 3 4 5 6 7 8 9 10 11 12
// 1   3 4 5   7 8 9    11 12
// 1 3 4 1 3 4 1 3 4


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
// 1 ... a[i] ... j... n