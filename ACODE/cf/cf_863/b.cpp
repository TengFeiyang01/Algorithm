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
    int n, x1, x2, y1, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    int c1 = std::max({x1, y1, n - x1 + 1, n - y1 + 1});
    int c2 = std::max({x2, y2, n - x2 + 1, n - y2 + 1});
    std::cout << abs(c1 - c2) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
