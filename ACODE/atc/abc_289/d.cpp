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
    int n, m, x;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::cin >> m;
	std::set<int> st;
	for (int i = 0; i < m; ++i) {
		int e;
		std::cin >> e;
		st.insert(e);
	}
	std::cin >> x;
	
	std::vector<bool> dp(N, false);
	dp[0] = true;

	for (int i = 1; i <= x; ++i) {
		if (st.count(i)) continue;
		for (auto s : a) {
			if (i >= s) {
				if (st.count(i - s)) continue;
				else dp[i] = dp[i] || dp[i - s];
			}
		}
	}
	if (dp[x]) {
		std::cout << "Yes";
	} else {
		std::cout << "No";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
