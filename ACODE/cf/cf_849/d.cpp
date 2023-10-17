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
	std::map<char, int> s1, s2;
	std::string s;
	std::cin >> n >> s;
	for (int i = 1; i < n; ++i) s2[s[i]]++;
	s1[s[0]]++;
	int l = s1.size(), r = s2.size();
	int ans = l + r;
	for (int i = 1; i < n - 1; ++i) {
		s1[s[i]]++;
		if (--s2[s[i]] == 0) s2.erase(s[i]);
		ans = std::max(sz(s1) + sz(s2), ans);
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
