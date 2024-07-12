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
const int N = 2e5 + 13;

void solve() {
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<int> a(n);
    std::vector<int> b(n);
	std::vector<int> c(m);

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        b[a[i]] = i;
    }

    for (int i = 0; i < m; ++i) std::cin >> c[i];
	int ans = inf;

    for (int i = 0; i < m - 1; ++i) {
        if (b[c[i]] < b[c[i + 1]]) {
            ans = std::min(b[c[i + 1]] - b[c[i]], ans);
        }
/*        if (b[c[i]] + d < n) {
            ans = std::min(ans, d - b[c[i]] - 1);
        } */
    }

    if (ans == inf) ans = 0;

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

