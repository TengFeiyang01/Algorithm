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
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

// void solve() {
//     int n;
//     std::cin >> n;
//     std::vector<std::array<i64, 2>> a(n);
//     for (int i = 0; i < n; ++i) std::cin >> a[i][1];
//     for (int i = 0; i < n; ++i) {
//         std::cin >> a[i][0];
//         a[i][0] = a[i][1] - a[i][0]; 
//     }
//     std::sort(a.begin(), a.end());
//     i64 ans = 0;

//     i64 l = -1, r = -1;

//     for (auto[x, y] : a) {
//         if (x >= r) {
//             ans += (r - l+ 1) * (r - l) / 2;
//             l = x;
//             r = y;
//         } else {
//             r = std::max(y, r);
//         }
//     }

//     ans += (r - l + 1) * (r - l) / 2;

//    	std::cout << ans << "\n";
// }

//逆序合并 O（n） 因为右端点有序
void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i][1];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0];
        a[i][0] = a[i][1] - a[i][0] + 1;
    }
    i64 ans = 0;
    auto[minL, r0] = a[n - 1];

    for (int i = n - 2; i >= 0; --i) {
        auto[r, l] = a[i];
        if (r < minL) {
            i64 x = (r0 - minL + 1);
            ans += (x + 1) * x / 2;
            r0 = r;
        } else {
            minL = std::min(minL, l);
        }
    }
    i64 x = (r0 - minL + 1);
    ans += x * (x + 1) / 2;
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
