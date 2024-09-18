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
	int n, k;
	std::cin >> n >> k;
	std::string s;
	std::cin >> s;
    std::vector<int> low(26);
    std::vector<int> up(26);
	for (auto c : s) {
		if (islower(c)) {
			low[c - 'a']++;
		} else {
			up[c - 'A']++;
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; ++i) {
		ans += std::min(up[i], low[i]);
		int dif = abs(up[i] - low[i]);
		if (k >= dif / 2) {
			k -= dif / 2;
			ans += dif / 2;
		} else {
			ans += k;
			k = 0;
		}
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
