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

int f[50];

void solve() {
    int n, x, y;
    std::cin >> n >> x >> y;

    std::function<bool(int, int, int)> dfs = [&](int n, int x, int y) ->bool {
    	if (n == 0) return true;
    	if (y > f[n]) return dfs(n - 1, f[n + 1] - y + 1, x);
    	else if (y <= f[n - 1]) return dfs(n - 1, y, x);

    	return false;
    };

    if (dfs(n, x, y)) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= 45; ++i)
    	f[i] = f[i - 1] + f[i - 2];

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
