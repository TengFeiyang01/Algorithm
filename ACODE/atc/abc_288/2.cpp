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
using PII = std::pair<int, std::string>;
const int N = 1e5 + 13;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<PII> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].second;
		a[i].first = i;
	}
	std::sort(all(a));
	std::sort(a.begin(), a.begin() + k, [&](auto c, auto d) {
		return c.second < d.second;
	});
	for (int i = 0; i < k; ++i)
		std::cout << a[i].second << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
