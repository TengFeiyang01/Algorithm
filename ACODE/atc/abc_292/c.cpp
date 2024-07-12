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

ll get(int x) {
	int cnt = 0;
	int i;
	for (i = 1; i * i < x; ++i) {
		if (x % i == 0) {
			cnt += 2;
		}
	}
	if (x / i == i) cnt++;
	return cnt;
}

void solve() {
	int n;
	ll ans = 0;
	std::cin >> n;

	for (int i = 1; i < n; ++i) {
		ans += get(i) * get(n - i);
	}
	std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
