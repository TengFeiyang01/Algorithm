#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> a(n);
    for (auto &[x, y] : a) {
    	std::cin >> x >> y;
    }
    std::sort(a.begin(), a.end(), [&](auto &x, auto &y){
    	if (x.first != y.first) {
    		return x.first < y.first;
    	} else {
    		return x.second > y.second;
    	}
    });

    i64 ans = 0;

    int cnt = 0, l = 0, r = 0;
    while (r < n) {
        if (a[r].first > cnt) {
        	cnt += 1;
        	ans += a[r].second;
        } else {
            r += 1;
            continue;
        }
        cnt = r - l + 1;
    	while (l < n and a[l].first <= cnt) {
    		l += 1;
    	}
        if (l == n) break;
        if (r >= l) cnt = r - l + 1;
        r += 1;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
