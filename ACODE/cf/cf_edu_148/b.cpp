#include <bits/stdc++.h>



#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    ll s = 0;
    std::cin >> n >> k;
    std::vector<ll> a(n + 1), presum(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }

    std::sort(a.begin(), a.end());
    for (int i = 1; i <= n; ++i) {
        presum[i] = presum[i - 1] + a[i];
    }
    ll suf = 0;
    int r = n;
    s = 0;

    for (int i = 0; i <= k; ++i) {
        ll cur = presum[n - k + i] - presum[i * 2];
        s = std::max(s, cur);
    }

    std::cout << s << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
