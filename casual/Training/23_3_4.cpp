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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& v : a) std::cin >> v;
    int ans = 0;
	std::vector<int> b(n), l(n);

	for (int i = 0; i < n; ++i) {
		int t, x;
		std::cin >> t;
		for (int j = 0; j < t; ++j) {
			std::cin >> x;
			b[i] |= (1 << (x - 1));
		}
	}

	
	for (int i = 0; i < 1 << n; ++i) {
		std::vector<int> c(n);
		for (int j = 0, k = i; j < n; ++j, k >>= 1) 
			c[j] = k & 1;
		
		bool ok = true;
	
		for (int j = 0; j < n && ok; ++j) 
			if (c[j] && b[j] && (i & b[j]) == b[j])
				ok = false;

		if (!ok) continue;
		int res = 0;
		for (int j = 0; j < n; ++j)
			if (c[j])
				res += a[j];
		ans = std::max(ans, res);
	}
	std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
