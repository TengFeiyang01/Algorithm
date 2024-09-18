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
using ull = unsigned long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
long double EPS = 1e-18;

// (b - k)^2 - 4ac < 0
//4ac > (b - k) ^ 2

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::array<long double, 3>> pros(m);
    std::vector<long double> line(n);
    for (int i = 0; i < n; ++i) std::cin >> line[i];
    std::sort(all(line));
    for (auto&[a, b, c] : pros) std::cin >> a >> b >> c;
    for (auto[a, b, c] : pros) {
        if (c <= 0) {
            std::cout << "NO\n";
            continue;
        }
        int l = upper_bound(all(line), b - (long double)2 * (long double)sqrt(a * c)) - line.begin();
        int r = lower_bound(all(line), b + (long double)2 * (long double)sqrt(a * c)) - line.begin();
        if (l == r) {
            std::cout << "NO\n";
            continue;
        }
        if (l != n) {
            std::cout << "YES\n";
            std::cout << ll(line[l]) << "\n";
        } else {
            std::cout << "NO\n";
        }
    }
    std::cout << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
