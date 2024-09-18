#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> a(n);
    std::vector<int> b;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    	b.push_back(a[i][0]);
    	b.push_back(a[i][1]);
    }
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    auto find = [&](int x) {
    	return std::lower_bound(b.begin(), b.end(), x) - b.begin();
    };
    int m = n * 2 + 2;
    std::vector<std::vector<int>> diff(31, std::vector<int>(m));

    for (int i = 0; i < n; ++i) {
    	int l = a[i][0], r = a[i][1], v = a[i][2];
    	l = find(l) + 1;
    	r = find(r) + 1;
        for (int j = 0; j < 30; ++j) {
            if (v >> j & 1) {
                diff[j][l]++;
                diff[j][r + 1]--;
            }
        }
    }
    int ans = 0;
    std::vector<int> cnt(31);
    for (int i = 0; i < m; ++i) {
        int tmp = 0;
        for (int j = 0; j < 30; ++j) {
            cnt[j] += diff[j][i];
            if (cnt[j]) {
                tmp |= 1 << j;
            }
        }
        ans = std::max(ans, tmp);
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
