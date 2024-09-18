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
const int N = 1e5 + 13, P = 131;
using ull = unsigned long long;

ull h[N], p[N];

ull get(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}

void solve() {
    int n, m;
    std::string s;
    std::cin >> n >> m >> s;
    int l1, l2, r1, r2;
	p[0] = 1;

	for (int i = 1; i <= n; ++i) {
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + s[i - 1];
	}

	while (m--) {
		std::cin >> l1 >> r1 >> l2 >> r2;

		if (get(l1, r1) == get(l2, r2)) std::cout << "Yes\n";
		else std::cout << "No\n";
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
