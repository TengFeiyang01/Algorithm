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
#define bg(x) begin(x) + 1
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
    ll n, s;
    std::cin >> n >> s;
    std::vector<ll> points(n + 1);
    std::vector<ll> sum(n + 1, 0LL);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> points[i];
    	points[i] += i + 0LL;
    }
	std::sort(all(points));
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + points[i];
	}
	int ans = lb(all(sum), s) - sum.begin();
    if (sum[ans] != s) ans--;
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
