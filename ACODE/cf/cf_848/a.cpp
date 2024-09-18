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
    std::vector<int> a(n);
    for (auto &c : a) std::cin >> c;
    int ans = -inf;
	int ok = 0;
   	int ne = 0;

    for (auto c : a) ne += (c == -1);
    for (int i = 1; i < n; ++i) {
    	if (a[i] == -1 && a[i - 1] == -1)
            ok = 1;
    }
	ans = std::accumulate(all(a), 0);
	if (ok) ans += 4;
	else {
		if (ne == 0) ans -= 4;
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
