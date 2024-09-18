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
const long double EPS = 1e-14;

/*
    xi + xj > C * (xi + xj + yi + yj)
    (1 - C) * xi - C * yi > (C - 1) * xj + C * yj
    满足左边大于右边的i, j对的数量
    
*/


void solve() {
    ll n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::array<int, 2>> a(n), b(m);
    for (ll i = 0; i < n; ++i) std::cin >> a[i][0] >> a[i][1];
    for (ll i = 0; i < m; ++i) std::cin >> b[i][0] >> b[i][1];
    long double l = 0, r = 1;
    auto check = [&](long double C) {
        std::vector<long double> A(n), B(m);
        for (ll i = 0; i < n; ++i) A[i] = (1.0 - C) * a[i][0] - C * a[i][1];
        for (ll i = 0; i < m; ++i) B[i] = (C - 1.0) * b[i][0] + C * b[i][1];
        std::sort(all(A)); std::sort(all(B));
        ll cur = 0, cnt = 0;
        for (ll i = 0; i < n; ++i) {
            while (cur < m and B[cur] < A[i])
              ++cur;
            cnt += cur;
        }
        return cnt < k;
    };


    while (r - l > EPS) {
        long double mid = (l + r) / 2.0;
        if (check(mid)) r = mid;
        else l = mid;
    }
    std::cout << std::fixed << std::setprecision(16) << l * 100;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
