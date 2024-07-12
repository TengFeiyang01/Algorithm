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
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	ll a, b;
	std::cin >> a >> b;
	std::vector<int> p, q;
	ll ans = 0;
	int l = log2(a);
	int r = log2(b);


	for (int i = 0; i <= 63; ++i) {
		for (int j = 0; j < i - 1; ++j) {
			ll cur = ((1LL << i) - 1LL) - (1LL << j);
			if (a <= cur and cur <= b) {
				ans++;
			}
		}
	}

	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
