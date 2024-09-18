#include <bits/stdc++.h>


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
	int neg = 0, pos = 0;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		if (a[i] < 0) neg++;
		else pos++;
	}
	int cur = 1;
	for (int i = 1; i <= pos; ++i) {
		std::cout << cur++ << " ";
	}
	cur--;
	for (int i = 0; i < neg; ++i) {
		std::cout << --cur << " \n"[i == neg - 1];
	}
	for (int i = 1; i <= neg; ++i) {
		std::cout << "1 0 ";
	}
	for (int i = 1; i <= (n - neg * 2); ++i) {
		std::cout << i << " ";
	}
	std::cout << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
