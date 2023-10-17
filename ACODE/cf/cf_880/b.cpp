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

void solve() {
    i64 ans = 0;
    i64 n, k, g;
    std::cin >> n >> k >> g;
    if (k == 1 and n == 2) {
    	std::cout << "0\n";
    	return;
    }
    i64 t = k * g;
    i64 x = g / 2 + g % 2;
    i64 y = (x - 1) * n;
    if (y >= t) {
        std::cout << t << "\n";
    } else {
        std::cout << std::max(0LL, t - g * ((t - y + g - 1) / g )) << "\n";
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
