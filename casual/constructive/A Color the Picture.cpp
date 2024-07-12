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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<ll> a(k);
    for (int i = 0; i < k; ++i) std::cin >> a[i];
    ll h = 0, c = 0;
	std::sort(a.begin(), a.end());
	for (auto x : a) {
		if (x / n > 1) h += x / n;
		//每个颜色至少两列/行 
		if (h == m - 1) h -= 2;
		if (x / m > 1) c += x / m;
		if (c == n - 1) c -= 2;
	}
	if (c >= n or h >= m) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
