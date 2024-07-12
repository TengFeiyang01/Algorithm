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
const int mod = 1e9;

void solve() {
    int n;
    std::cin >> n;
    n >>= 1;
    std::vector<ll> f(n + 1);
    f[0] = 1;
    // for (int j = 0; (1 << j) <= n; ++j)
    //     for (int i = 0; i <= n; ++i)
    //         if (i - (1 << j) >= 0)
    //             f[i] = (f[i] + f[i - (1 << j)]) % mod;
    for (int i = 1; i <= n; ++i)
        f[i] = (f[i - 1] + f[i >> 1]) % mod;

    std::cout << f[n] % mod;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
