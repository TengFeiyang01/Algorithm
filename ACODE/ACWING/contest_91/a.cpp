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
	std::string s;
	std::cin >> s;
	int n = s.size();
	std::vector<std::string> a;
	for (int i = 0; i < n; ++i) {
		if (s[i] != '0') {
			a.push_back(s[i] + std::string(n - i - 1, '0'));
		}
	}
	std::cout << sz(a) << "\n";
	for (int i = 0; i < sz(a); ++i) {
		std::cout << a[i] << " \n"[i == sz(a) - 1];
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
	int t;
	std::cin >> t;
	while (t--)
	    solve();

    return 0;
}
