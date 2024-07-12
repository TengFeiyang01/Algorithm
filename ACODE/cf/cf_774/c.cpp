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
constexpr ll limit = 1e12;

void solve() {
    ll n;
    std::cin >> n;
    std::vector<ll> a(15);
    ll t = 1;
    a[0] = 1LL;
    for (int i = 1; i < 15; ++i) {
    	a[i] = a[i - 1] * t;
    	t++;
    }

    int ans = inf;
    //枚举选了哪个阶乘

    for (int i = 0; i < 1 << 15; ++i) {
        ll cur = 0;
        int cnt = 0;
        for (int j = 0; j < 15; ++j) {
            if (i >> j & 1) {
                if (j >= 3) {
                    cur += a[j];
                    cnt++;
                }
            }
        }
        if (n - cur >= 0) {
            ans = std::min(ans, __builtin_popcountll(n - cur) + cnt);
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
