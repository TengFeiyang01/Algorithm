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
const int N = 2e5 + 13;

/*
这是一个根号的做法:
	对于每一个被染色的点，我们以其为中心，进行BFS。
	BFS的途中，类似于最短路，维护一个dis[]
	记录之前的答案ans，显然ans是越来越小的
	BFS的途中，只有dis[v]可以被更新，且更新后的答案小于ans，我们才去更新
*/

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> c(n);
	for (int i = 0; i < n; ++i) std::cin >> c[i], c[i]--;
	vector g(n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		std::cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	std::vector<int> dist(n, n);

	
	int ans = n;
	for (int i = 0; i < n; ++i) {
		ans = std::min(ans, dist[c[i]]);
		if (i) std::cout << ans << " \n"[i == n - 1];
		std::queue<int> q;

		q.push(c[i]);
		dist[c[i]] = 0;

		while (sz(q)) {
			int t = q.front();
			q.pop();

			for (int v : g[t]) {
				if (dist[v] > dist[t] + 1 && ans > dist[t] + 1) {
					dist[v] = dist[t] + 1;
					q.push(v);
				}
			}

		}
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
