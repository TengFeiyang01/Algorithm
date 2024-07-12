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
    ll n, m, d;
    std::cin >> n >> m >> d;
    std::vector<ll> a(n);
    std::set<ll> b;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        ll x;
        std::cin >> x;
        b.insert(x);
    }

    ll ans = 0;
    bool ok = false;

    for (int i = 0; i < n; ++i) {
        auto it = b.upper_bound(a[i] + d);
        if (it == b.begin()) continue;
        --it;
        if (*it >= a[i] - d and *it <= a[i] + d) {
            ok = 1;
            ans = std::max(ans, a[i] + *it);
        }
    }

    if (ok)
        std::cout << ans << "\n";
    else std::cout << "-1\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    solve();

    return 0;
}
