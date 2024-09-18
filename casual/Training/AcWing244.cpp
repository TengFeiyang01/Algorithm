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
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n;
int tr[N];

void add(int x, int v) {
	while (x <= n) {
		tr[x] += v;
		x += x & -x;
	}
}

int query(int x) {
	int ans = 0;
	while (x) {
		ans += tr[x];
		x &= x - 1;
	}
	return ans;
}

void solve() {
	std::cin >> n;
	int h[N];
	
	for (int i = 1; i <= n; ++i) tr[i] = i & -i;

	for (int i = 2; i <= n; ++i) std::cin >> h[i];
	
	int ans[N];
	for (int i = n; i; --i) {
		int l = 1, r = n;
		int k = h[i] + 1;
		while (l < r) {
			int mid = l + r >> 1;
			if (query(mid) >= k) r = mid;
			else l = mid + 1;
		}
		ans[i] = l;
		add(l, -1);
	}
	for (int i = 1; i <= n; ++i) std::cout << ans[i] << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
