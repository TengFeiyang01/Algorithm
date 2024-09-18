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
#define first x
#define second y



void solve() {
    ll n, k;
    std::cin >> n >> k;
    ll l1, l2, r1, r2;
    std::cin >> l1 >> r1 >> l2  >> r2;
    if (l1 > l2) std::swap(l1, l2);
    if (r1 > r2) std::swap(r1, r2);

    ll ans = 0;
    k -= n * std::max(0LL, r1 - l2);

    if (k <= 0) {
    	ans = 0;
    } else {
        //cost1 使得它两相交的花费
    	ll cost1 = std::max(0LL, l2 - r1);
        
    	ll t1 = r2 - l1 - std::max(0LL, r1 - l2);

        //花费1即可 
        if (k <= t1) ans = cost1 + k;
        else {
            //需要2换1
            ans = cost1 + t1 + (k - t1) * 2;
            ll c = t1 == 0 ? n : std::min(n, k / t1);
            ll t2 = k - c * t1;
            ans = std::min(ans, (cost1 + t1) * c + 2 * t2);
            if (c < n) {
                ans = std::min(ans, (cost1 + t1) * c + cost1 + t2);
            }
        }
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
