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
#define all(x) bg(x) + 1, end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;

const int N = 1e5 + 10;

void solve() {
    int m, n;
    std::cin >> m >> n;

	std::vector a(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
    	for (int j = 1; j <= n; ++j) {
    		std::cin >> a[i][j];
    	}


	auto check = [&](int k) ->bool {
		for (int j = 1; j <= n; ++j) {
			bool f1 = 0;
			for (int i = 1; i <= m; ++i)
				if (a[i][j] >= k) f1 = 1;
			if (!f1) return false;
		}
		//每一列都有大于k的
		//选n - 1行 即 存在一行 该行有两个大于 k的
		for (int i = 1; i <= m; ++i) {
			int c = 0;
			for (int j = 1; j <= n; ++j) if (a[i][j] >= k) c++;
			if (c >= 2) return true;
		}
		return 0;
	};

	int l = 1, r = 1e9;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
