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
    int n, m;
    std::cin >> n >> m;

    std::vector<PII> g[n + m];
    std::vector<int> d(n + m), dist(n + m);

    for (int i = 0; i < m; ++i) {
    	int t, x, start = n - 1, end = 0;
    	std::cin >> t;
		std::vector<int> st(n, 0);
		for (int i = 0; i < t; ++i) {
			std::cin >> x;
			x--;
			start = std::min(start, x);
			end = std::max(end, x);
			st[x] = 1;
		}
		int ver = n + i;
		for (int j = start; j <= end; ++j) {
			if (!st[j]) {
				g[j].eb(ver, 0);
				d[ver]++;
			} else {
				g[ver].eb(j, 1);
				d[j]++;
			}
		}
    }
	std::vector<int> order(n + m);
	auto toposort = [&]() {
		std::queue<int> q;
		for (int i = 0; i < n + m; ++i) {
			if (!d[i]) {
				q.push(i);
			}
		}
		while (q.size()) {
			int t = q.front();
			order.push_back(t);
			q.pop();
			for (auto[y, _] : g[t]) {
				if (--d[y] == 0) {
					q.push(y);
				}
			}
		}
	};
	
	toposort();

	int res = 0;
	for (int i = 0; i < n; ++i) dist[i] = 1;

	for (int x : order) {
		for (auto[y, w] : g[x])
			dist[y] = std::max(dist[x] + w, dist[y]);
	}
	
	for (int i = 0; i < n; ++i) res = std::max(res, dist[i]);
	std::cout << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
