#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 ans = 0;
    int n, m;
    std::cin >> n >> m;
   	std::map<int, i64> cnta, cntb;
   	for (int i = 1; i <= n; ++i) {
   		cnta[i % 5]++;
   	}
   	for (int i = 1; i <= m; ++i) {
   		cntb[i % 5]++;
   	}
   	for (int i = 0; i <= 4; ++i) {
   		ans += cnta[i] * (cntb[(5 - i) % 5]);
   	}
   	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
