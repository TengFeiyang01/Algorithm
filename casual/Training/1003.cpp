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

int dfs(int n) {
	if (n <= 2) return 0;
	else if (n & 1) return dfs(n / 2) + dfs(n / 2 + 1) + 1;
	else return 2 * dfs(n / 2);
}

void solve() {
    int n;
    std::cin >> n;
    std::cout << dfs(n) << "\n"; 
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
