#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>

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
    ll a, b, n, m;
    std::cin >> a >> b;
    std::cin >> n >> m;
    if (n >= m + 1) {
        ll s1 = (n / (m + 1)) * a * m + std::min(a, b) * (n % (m + 1));
        ll s2 = b * n;
        std::cout << std::min(s1, s2) << "\n";
    } else {
        ll s1 = n * a;
        ll s2 = b * n;
        std::cout << std::min(s1, s2) << "\n";
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
