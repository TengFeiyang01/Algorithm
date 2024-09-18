#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> m >> n;
    std::vector<int> cnt(m + 2), cnt2(m + 2);
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
    	int l, r;
    	std::cin >> l >> r;
    	cnt[l]++;
    	cnt[r + 1]--;
    	a[i] = {l, r};
    }
    for (int i = 1; i <= m; ++i) {
    	cnt[i] += cnt[i - 1];
    	cnt2[i] += cnt2[i - 1];

    	if (cnt[i] >= 2) {
    		cnt2[i]++;
    	}
    }
    
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	int l = a[i][0], r = a[i][1];
    	if (cnt2[r] - cnt2[l - 1] == r - l + 1) {
    		ans++;
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
