#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<ll, ll>;
const int N = 1e5 + 13;

void solve() {
    ll ans = 0LL, n, m, L;
    std::cin >> L >> n >> m;
    std::vector<PII> a(n), b(m);
    for (auto&[x, y] : a) {
    	std::cin >> x >> y;
    }
    for (auto&[x, y] : b) {
    	std::cin >> x >> y;
    }

    for (int i = 0, j = 0; i < n; i += !a[i].second, j += !b[j].second) {
    	ll now = a[i].second;
    	now = std::min(now, b[j].second);
    	if (a[i].first == b[j].first) {
    		ans += now;
    	}
    	a[i].second -= now;
    	b[j].second -= now;
    }
    std::cout << ans << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
