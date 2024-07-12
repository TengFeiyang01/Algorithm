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
const int N = 20, mod = 1e9 + 7;

int a[N];
ll Pow10[N];

struct F{
	ll s0, s1, s2;
	F() : s0(0LL), s1(0LL), s2(0LL) {}
	F(ll _0, ll _1, ll _2) : s0(_0), s1(_1), s2(_2) {}
	void operator+=(const F& t) {
		s0 = (s0 + t.s0) % mod;
		s1 = (s1 + t.s1) % mod;
		s2 = (s2 + t.s2) % mod;
	}
}f[N][N][N];

F dp(ll pos, ll val, ll sum, bool is_limit) {
	if (!pos) {
		if (val && sum) return {1, 0, 0};
		return {0, 0, 0};
	}

	if (!is_limit && ~f[pos][val][sum].s0) return f[pos][val][sum];
	F ans(0, 0, 0);
	int up = is_limit ? a[pos] : 9;
		if (i == 7) continue;
		F t = dp(pos - 1, (val * 10 + i) % 7, (sum + i) % 7, is_limit && i == a[pos]);
		
		ll k = (ll)i * Pow10[pos - 1] % mod;

		t.s2 = (t.s2 + 2LL * k % mod * t.s1 % mod) % mod;
		t.s2 = (t.s2 + k * k % mod * t.s0 % mod) % mod;
		
		t.s1 = (t.s1 + k * t.s0 % mod);

		ans += t;
	}
	return is_limit ? ans : f[pos][val][sum] = ans;
}

ll calc(ll n) {
	int pos = 0;
	while (n) a[++pos] = n % 10, n /= 10;
	return dp(pos, 0, 0, 1).s2;
}

void solve() {
    ll l, r;
    memset(f, -1, sizeof f);
    std::cin >> l >> r;
    std::cout << (calc(r) - calc(l - 1) + mod) % mod << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
	
	Pow10[0] = 1;
	for (int i = 1; i < 20; ++i) Pow10[i] = 10LL * Pow10[i - 1] % mod;

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
 