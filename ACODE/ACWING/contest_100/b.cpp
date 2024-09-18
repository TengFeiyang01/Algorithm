#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, l, r, x;
    std::cin >> n >> l >> r >> x;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < 1 << n; ++i) {
    	int s = 0, mx = 0, mi = inf;
    	for (int j = 0; j < n; ++j) 
    		if (i >> j & 1) {
    			s += a[j];
    			mx = std::max(mx, a[j]);
    			mi = std::min(mi, a[j]);
    		}
    	if (mx - mi >= x and l <= s and s <= r)
    		ans += 1;
    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
