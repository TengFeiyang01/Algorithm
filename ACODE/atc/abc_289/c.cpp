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
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(m, 0);
	for (int i = 0; i < m; ++i) {
		int t;
		std::cin >> t;
		for (int j = 0; j < t; ++j) {
			int x;
			std::cin >> x;
			a[i] |= (1 << (x - 1));
		}
	}
	int ans = 0;
	int mask = (1 << n) - 1;
	for (int i = 0; i < 1 << m; ++i) {
		int t = 0;
		for (int j = 0; j < m; ++j) {
			if ((i >> j) & 1) {
				t |= a[j];
			}
		}
		if ((t & mask) == mask) {
			ans++;
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
