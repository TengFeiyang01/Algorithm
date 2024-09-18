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
const int N = 1e5 + 13;
const int mod = 1e9 + 7;

ll qmi(ll a, ll b, ll p) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		b >>= 1;
		a = (a * a) % p;
	}
	return res;
}

void solve() {
    ll res = 1;
	int n;
	std::cin >> n;
	int a = 2 * n, b = n;
	for (int i = a; i > a - b; --i) res = res * i % mod;
	for (int i = 1; i <= b; ++i) res = res * qmi(i, mod - 2, mod) % mod;

	res = res * qmi(n + 1, mod - 2, mod) % mod;

	std::cout << res;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
