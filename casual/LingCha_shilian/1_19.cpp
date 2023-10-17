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
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<std::vector<int>, std::vector<int>>;
const int N = 1e5 + 13;

void solve() {
    int n, ans = 0;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
	std::vector<PII> q;   
    q.eb(a, b);

    int ok = 0;

    for (int i = 29; i >= 0; --i) {
        auto t = q;
        q.clear();
        for (auto p : t) {
            vector f(2), g(2);
            for (int v : p.first) {
                f[v >> i & 1].eb(v);
            } 
            for (int v : p.second) {
                g[v >> i & 1].eb(v);
            }
            if (sz(f[0]) != sz(g[1])) {
                q = t;
                ok = 1;
                break;
            }
            if (sz(f[0])) q.eb(f[0], g[1]);
            if (sz(f[1])) q.eb(f[1], g[0]); 
        }
        if (ok) {
            ok = 0;
            continue;
        }
        ans |= 1 << i;
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
