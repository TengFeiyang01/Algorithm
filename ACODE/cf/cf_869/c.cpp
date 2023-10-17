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
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    std::vector<int> pos;
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] <= a[i - 1] and a[i] >= a[i + 1]) {
			pos.emplace_back(i);
		}
	}

	auto get = [&](int l, int r) {
		return ub(all(pos), r - 1) - lb(all(pos), l + 1);
	};
	for (int i = 0; i < q; ++i) {
		int l, r;
		std::cin >> l >> r;
		l--, r--;
		if (r - l + 1 <= 2) {
			std::cout << r - l + 1 << "\n";
		} else {
			std::cout << r - l + 1 - get(l, r) << "\n";
		}
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
	solve();

    return 0;
}
