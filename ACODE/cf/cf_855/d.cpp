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
// const int N = 2e5 + 13, P = 131;
// using ull = unsigned long long;

// ull h[N], p[N];

// ull qmi(ull a, ull b) {
// 	ull res = 1;
// 	while (b) {
// 		if (b & 1) res *= a;
// 		a *= a;
// 		b >>= 1;
// 	}
// 	return res;
// }

// ull get(int l, int r) {
// 	return h[r] - h[l - 1] * qmi(P, r - l + 1);
// }

// int n;
// std::string s;

// void init() {
//     int l1, l2, r1, r2;
// 	p[0] = 1;
// 	for (int i = 1; i < N; ++i) {
// 		p[i] = p[i - 1] * P;
// 	}
// }


// void solve() {
//     std::cin >> n >> s;
// 	std::set<ull> st;
// 	s = " " + s;

// 	for (int i = 1; i <= n; ++i) h[i] = h[i - 1] * P + s[i];

// 	int ans = 0;

// 	for (int i = 1; i <= n; ++i) {
// 		ull t1 = 0;
// 		if (i > 1) t1 = get(1, i - 1);
// 		ull t2 = 0;
// 		if (i + 2 <= n) t2 = get(i + 2, n);
// 		ull t3 = p[n - i - 1];
// 		ull x = t1 * t3 + t2;
// 		if (!st.count(x)) {
// 			st.insert(x);
// 			ans++;
// 		}
// 	}
 
// 	std::cout << ans - 1 << "\n";
// }

void solve() {
	int n;
	std::string s;
	std::cin >> n >> s;
	int ans = n - 1;
	for (int i = 0; i + 2 < n; ++i) {
		ans -= (s[i] == s[i + 2]);
	}
	std::cout << ans << "\n";
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    //init();
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
