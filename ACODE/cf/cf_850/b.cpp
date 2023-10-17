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
 
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	int n, w, h;
	std::cin >> n >> w >> h;
    std::vector<int> a(n);
    std::vector<int> b(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	for (int i = 0; i < n; ++i) std::cin >> b[i];
	
	int l = -inf, r = inf;
	for (int i = 0; i < n; ++i) {
		int la = a[i] - w, ra = a[i] + w;
		int lb = b[i] - h, rb = b[i] + h;
		l = std::max(la - lb, l);
		r = std::min(ra - rb, r);
	}
	int ok = 1;
	if (l > r) {
		ok = 0;
	}

	if (ok) std::cout << "YES\n";
	else std::cout << "NO\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
