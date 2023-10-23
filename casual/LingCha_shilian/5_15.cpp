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
    int n;
    std::cin >> n;
    int v, z = -1, m = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> v;
        if (v % 5 == 0) {
            v += v % 10;
            if (z == -1) {
                z = v;
            } else if (z != v) {
                z = -2;
            }
        } else {
            m |= 1 << (v % 20);
        }
    }

    if (m > 0) {
        if (z == -1 and ((m & 729366) == 0 or (m & 729366) == m)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        } 
    } else {
        if (z != -2) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
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
