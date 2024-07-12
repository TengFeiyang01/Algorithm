#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, p, d;
    std::cin >> n >> p >> d;
    std::vector<i64> a(n);
    i64 sum = 0, tot = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (i < d) sum += a[i];
    }
    int ans = d;
    std::deque<std::array<i64, 2>> q;
    q.push_back({sum, 0});
    tot = sum;

    for (int l = 0, r = d; r < n; ++r) {
    	sum += a[r] - a[r - d];
    	while (!q.empty() and q.back()[0] <= sum) q.pop_back();
    	q.push_back({sum, r - d + 1});

    	tot += a[r];
    	while (tot - q.front()[0] > p) {
    		tot -= a[l++];
    		while (q.front()[1] < l) q.pop_front();
    	}
    	ans = std::max(ans, r - l + 1);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
