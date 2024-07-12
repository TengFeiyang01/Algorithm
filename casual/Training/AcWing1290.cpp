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
const ll mod = 100003;

ll qpow(ll x, ll y) {
    ll res = 1;
    for (; y; y /= 2, x = x * x % mod)
        if (y & 1)
            res = res * x % mod;
    return res;
}

void solve() {
    ll a, b;
    std::cin >> a >> b;
    std::cout << ((qpow(a, b) - a * qpow(a - 1, b - 1)) % mod + mod) % mod;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
