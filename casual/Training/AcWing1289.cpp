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
const int mod = 200907;

int qpow(ll x, ll y) {
    ll res = 1;
    for (; y; y /= 2, x = x * x % mod)
        if (y & 1)
            res = res * x % mod;
    return res;
}

void solve() {
    ll a, b, c, k;
    std::cin >> a >> b >> c >> k;
    if (b - a == c - b) {
    	std::cout << (a + (b - a) * (k - 1)) % mod << "\n";
    } else {
    	ll p = b / a;
    	std::cout << (a * qpow(p, k - 1)) % mod << "\n";
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