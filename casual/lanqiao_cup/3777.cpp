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

void update(char &c) {
	c = (c == 'W') ? 'B' : 'W';
}

bool check(std::string s, char c) {
	std::vector<int> ans;
	for (int i = 0; i < s.size() - 1; ++i) {
		if (s[i] != c) {
			ans.pb(i);
			update(s[i]);
			update(s[i + 1]);
		}
	}
	if (s[0] != s.back()) return false;

	std::cout << sz(ans) << "\n";
	for (int i = 0; i < sz(ans); ++i) {
		std::cout << ans[i] + 1 << " \n"[i == sz(ans) - 1];
	}
	return true;
}

void solve() {
    int n;
    std::cin >> n;
    std::string s;
	std::cin >> s;

	if (!check(s, 'B') && !check(s, 'W')) std::cout << "-1\n";	
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
