#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>

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
const int N = 1e6 + 13;
int Log[N]{0};

void init() {
	int k = 0;	
	for (int i = 1; i < N; ++i) {
		if (i < (1 << k)) {
			Log[i] = k;
		} else {
			k++;
			Log[i] = k;
		}
	}
}

const int MOD = 998244353;


void solve() {
	ll l, r;
	std::cin >> l >> r;
	ll cnt = 0, x = l, a = 1;
	while (x <= r) {
		cnt++;
		x <<= 1;
		a <<= 1;
	}
	x >>= 1;
	a >>= 1;

	if (a == 0) {
		std::cout << "1 1\n";
		return;
	}

	ll ans = (r - x + a) / a;
	if ((x / 2) * 3 <= r && (x / 2 * 3 >= l)) {
		x = x / 2 * 3;
		a = a / 2 * 3;
		if (a) {
			ans += (cnt - 1) * ((r - x + a) / a) % MOD;
		}
	}
	std::cout << cnt << " " << ans % MOD << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    init();
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
