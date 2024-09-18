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
    std::vector<int> c(n);
	ll s = 0;
	for (int &v : c) std::cin >> v, s += (ll)v;
	ll k = s / (ll)n;
	std::vector<int> d(n), a(n);
	int sd = 0;
	for (int i = n - 1; i >= 0; --i) {
		sd += d[i];
		if (c[i] + sd == i + 1) 
			a[i] = 1;
		sd--;
		if (i - k >= 0) d[i - k]++;
		if (a[i] == 1) k--;
	}
	for (int i = 0; i < n; ++i)
		std::cout << a[i] << " \n"[i == n - 1];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
