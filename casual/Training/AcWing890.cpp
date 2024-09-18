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
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(m);
    for (int &v : a) std::cin >> v;
    int ans = 0;
	for (int i = 1; i < 1 << m; ++i) {
		int s = 0; ll x = 1;
		for (int j = 0; j < m; ++j) {
			if (i >> j & 1) {
				if (x * a[j] > n) {
					x = -1;
					break;
				}
				x *= a[j];
				s++;y
			}
		}
		if (x != -1) {
			if (s % 2) ans += n / x;
			else ans -= n / x;
		}
	}
	std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
