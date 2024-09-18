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
    std::vector<int> idg(n + 1);
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	idg[y]++;
    	g[x].pb(y);
    }
    if (m < n - 1) {
    	std::cout << "No\n";
    	return;
    }
	int ok = 1;
	int cnt = 0;
    std::vector<int> ans(n + 1);
    std::queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (idg[i] == 0) {
			cnt++;
			ans[i] = 1;
			q.push(i);
		}
	}
	if (cnt > 1) ok = 0;
	int t = 1;
    while (q.size()) {
		auto x = q.front();
		q.pop();
    	for (int y : g[x]) {
    		if (--idg[y] == 0) {
    			q.push(y);
    			ans[y] = ans[x] + 1;
    		}
    	}
    }

	std::set<int> s;
	for (int i = 1; i <= n; ++i) {
		if (ans[i])
			s.insert(ans[i]);
	}
	
	if (sz(s) == n) {
		std::cout << "Yes\n";
		for (int i = 1; i <= n; ++i) {
			std::cout << ans[i] << " \n"[i == n];
		}
		return;
	}
	std::cout << "No\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
