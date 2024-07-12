#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int m, n;
    std::cin >> m >> n;
    std::vector<int> a(n);
    int s = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    }
    if (s % 2 or s != 2 * m) {
    	std::cout << "-1\n";
    	return;
    }
    std::vector<std::vector<int>> f(n + 2, std::vector<int>(m + 1, -inf));
    f[n + 1][0] = 0;
    for (int i = n; i >= 1; --i) {
        for (int j = 0; j <= m; ++j) {
            int x = a[i - 1];
            f[i][j] = f[i + 1][j];
            if (j >= a[i - 1]) f[i][j] = std::max(f[i + 1][j - x] + x, f[i][j]);
        }
    }


    if (f[1][m] != m) {
        std::cout << -1 << "\n";
        return;
    }

    std::multiset<int> ans, res;

    for (int i = 1, j = m; i <= n; ++i) {
        if (j >= a[i - 1] && f[i][j] == f[i + 1][j - a[i - 1]] + a[i - 1]) {
    		ans.insert(a[i - 1]);
    		j -= a[i - 1];
    	} else {
    		res.insert(a[i - 1]);
    	}
    }

    int x = *ans.begin(), y = *res.begin();
    if (x > y or (x == y and ans.size() < res.size())) {
    	std::swap(ans, res);
    }
    for (int x: ans) {
    	std::cout << x << " ";
    }
    std::cout << "\n";
    for (int x : res) {
    	std::cout << x << " ";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
