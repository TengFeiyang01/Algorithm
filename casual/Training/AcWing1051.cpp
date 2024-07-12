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
    std::vector<int> a(n + 1), f(n + 2, -inf), g(n + 2, -inf);
    for (int i = 1; i <= n; ++i)
    	std::cin >> a[i];
    int s = 0;
    for (int i = 1; i <= n; ++i) {
    	s = std::max(0, s) + a[i];
    	f[i] = std::max(f[i - 1], s);
    }
    s = 0;
    for (int i = n; i >= 1; --i) {
    	s = std::max(s, 0) + a[i];
    	g[i] = std::max(g[i + 1], s);
    }

    int ans = -inf;
    for (int i = 1; i <= n; ++i)
    	ans = std::max(f[i] + g[i + 1], ans);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    solve();

    return 0;
}
