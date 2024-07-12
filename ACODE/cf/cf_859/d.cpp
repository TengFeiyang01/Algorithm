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
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    ll s, n, m;
    std::cin >> n >> m;
    std::vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	a[i] += a[i - 1];
    }
    s = a[n];
    while (m--) {
    	ll l, r, k;
    	std::cin >> l >> r >> k;
    	ll remain = s - (a[r] - a[l - 1]);
    	if ((remain + k * (r - l + 1)) % 2) {
    		std::cout << "YES\n";
    	} else {
    		std::cout << "NO\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
