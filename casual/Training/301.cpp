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
    std::vector<int> a(n * 2 + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i], a[i] += a[i - 1];
    for (int i = n + 1; i <= n * 2; ++i) a[i] = a[i - n] + a[n];

    std::vector<std::vector<int>> f(n * 2 + 1, std::vector<int>(n * 2 + 1, inf));
	for (int i = 1; i <= n * 2; ++i) f[i][i] = 0;
	for (int len = 1; len < n; ++len)
		for (int l = 1; l + len <= n * 2; ++l) {
            int r = l + len;
			for (int k = l; k < r; ++k)
				f[l][r] = std::min(f[l][r], f[l][k] + f[k + 1][r] + a[r] - a[l - 1]);
        }
    int ans = inf;
    for (int i = 1; i <= n; ++i) ans = std::min(ans, f[i][i + n - 1]);
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
