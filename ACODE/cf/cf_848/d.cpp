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
int INV[N];

ll n1 = 998244353;

void init() {
    INV[0] = INV[1] = 1;
	for (ll i = 2; i < N; ++i) {
		INV[i] = n1 - n1 / i * INV[n1 % i] % n1;
	}
}

void solve() {
    ll n, x = 1, dif = 0, y = 1; 
    std::string s1, s2;
	std::cin >> n >> s1 >> s2;
	for (int i = 0; i < sz(s1); ++i) dif += s1[i] != s2[i];
	for (ll i = n; i >= 2; --i) {
		ll t = (n * INV[i] % n1);
		x = ((t + (t - 1) * x) % n1 + n1) % n1;
		y = (y + (i <= dif) * x) % n1;
	}
	if (dif == 0) std::cout << "0\n";
	else std::cout << ((x * (n - 1) + y + n) % n1) % n1 - 1 << "\n";

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
