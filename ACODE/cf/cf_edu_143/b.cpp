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
    std::vector<int> cnt(100);
	std::vector<std::array<int, 2>> seg(n);
	for (auto&[l, r] : seg) std::cin >> l >> r;
	int s = 0;
	for (auto[l, r] : seg) {
		if (l <= k && r >= k) {
			cnt[l]++;
			cnt[r + 1]--;
		}
	}
	int mx = -1;
	for (int i = 1; i < 51; ++i) cnt[i] += cnt[i - 1];
	for (int i = 1; i < 51; ++i) mx = std::max(mx, cnt[i]);
	
	if (cnt[k] == mx) {
		for (int i = 1; i < 51; ++i) {
			if (cnt[i] == mx) {
				s++;
			}
		}
		if (s == 1)
			std::cout << "YES\n";
		else std::cout << "NO\n";
	} else {
		std::cout << "NO\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
