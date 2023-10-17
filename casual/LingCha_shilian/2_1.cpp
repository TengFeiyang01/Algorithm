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
	ll n, s = 0LL;
	std::cin >> n;
    std::vector<ll> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		b[i] = i;
		s += a[i] * i;
	}

	auto output = [&]() {
		std::cout << "Yes\n";
		for (int i = 0; i < n; ++i)
			std::cout << b[i] << " \n"[i == n - 1];
	};
	if (s == 0) {
		output();
		return;
	}

	if (s > 0 == (a[0] > 0)) {
		b[0] = -s * a[0];
		output();
		return;
	}
	
	if (s > 0 == (a[n - 1] < 0)) {
		b[n - 1] = -(s - (n - 1) * a[n - 1]) * a[n - 1];
		output();
		return;
	}
	ll pre = 0;

	for (int i = 0; i < n; ++i) {
		pre += a[i];
		if (pre != 0 && pre > 0 == (a[n - 1] > 0)) {
			s = 0;
			for (int j = i + 1; j < n; ++j)
				s += j * a[j];
			for (int j = 0; j < i; ++j) {
				b[j] = j - 1e12;
				s += b[j] * a[j];
			}
			b[i] = -s * a[i];
			output();
			return;
		}
	}
	ll suf = 0;
	
	for (int i = n - 1; i >= 0; --i) {
		suf += a[i];
		if (suf != 0 && suf > 0 == (a[0] > 0)) {
			s = 0;
			for (int j = 1; j < i; ++j) 
				s += j * a[j];
			for (int j = i + 1; j < n; ++j) {
				b[j] = 1e12 - (n - 1 - j);
				s += b[j] * a[j];
			}
			b[i] = - s * a[i];
			output();
			return;
		}
	}
	std::cout << "No\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
	
	solve();

    return 0;
}
