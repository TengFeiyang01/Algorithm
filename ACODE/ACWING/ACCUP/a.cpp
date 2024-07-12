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
    // int ans = 1e9, x = 1, n;
    // std::cin >> n;
    // std::function<void(int, int)> dfs = [&](int i, int j)->void {
    // 	if (i == 1) {
    // 		ans = std::min(ans, j + 1);
    // 		return;
    // 	}
    // 	if (j > ans) return;
    // 	if (i % 2) {
    // 		dfs(i / 2, j + 1);
    // 	} else {
    // 		dfs(i / 2, j);
    // 	}
    // };
    // dfs(n, 0);
    // std::cout << ans << "\n";
	ll n, ans = 0;
	std::cin >> n;
	while (n) {
		n &= n - 1;
		ans++;
	}
	std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
