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
    std::vector<int> g[n + 1];
    std::vector<int> d(n + 1);
	std::vector<int> order;

    std::vector<PII> edge;
    for (int i = 0; i < m; ++i) {
    	int t, a, b;
    	std::cin >> t >> a >> b;
     	if (!t) {
     		edge.eb(a, b);
     	} else {
     		g[a].eb(b);
     		d[b]++;
     	}
    }
	auto toposort = [&]() ->bool {
		int cnt = 0;
		std::queue<int> q;
		for (int i = 1; i <= n; ++i) {
			if (!d[i]) {
				q.push(i);
			}
		}
		while (q.size()) {
			int t = q.front();
			order.push_back(t);
			cnt++;
			q.pop();
			for (int y : g[t]) {
				if (--d[y] == 0) {
					q.push(y);
				}
			}
		}
		return cnt == n;
	};
	//如果已有的边已经成环 肯定不行
	if (!toposort()) std::cout << "NO\n";
	else {
		//否则只需要按照拓扑排序中的顺序输出即可
		std::cout << "YES\n";
		for (int i = 1; i <= n; ++i)
			for (int v : g[i])
				std::cout << i << " " << v << "\n";
		std::vector<int> pos(n + 1);
		for (int i = 0; i < n; ++i) pos[order[i]] = i;
		for (auto[a, b] : edge) {
			if (pos[a] > pos[b]) std::swap(a, b);
			std::cout << a << " " << b << "\n";
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
