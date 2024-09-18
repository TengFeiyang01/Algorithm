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
    int n, k, z;
    std::cin >> n >> k >> z;
    int ans = 0, s = 0, mx = 0;
    std::vector<int> a(n + 2);
    k += 1;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];

    for (int i = 1; i <= k; ++i) {
        s += a[i];
        if (i < n) mx = std::max(mx, a[i] + a[i + 1]);
        ans = std::max(ans, std::min(z, (k - i) / 2) * mx + s);
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
