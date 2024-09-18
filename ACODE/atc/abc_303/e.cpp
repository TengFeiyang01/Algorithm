#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> d(n);
    std::vector<int> g[n];
    for (int i = 0; i < n - 1; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	d[x - 1]++;
    	d[y - 1]++;
    	g[x - 1].emplace_back(y - 1);
    	g[y - 1].emplace_back(x - 1);
    }
    std::vector<int> st(n);
    std::queue<int> q;

   	for (int i = 0; i < n; ++i) {
   		if (d[i] == 1) {
   			q.push(i);
   		}
   	}

    std::vector<int> ans;
    std::function<int(int, int)> dfs = [&](int u, int deep) ->int {
    	if (deep > 2) return 0;
    	st[u] = 1;
    	int res = 1;
    	for (int v : g[u]) {
    		if (!st[v]) {
    			res += dfs(v, deep + 1);
    			q.push(v);
    		}
    	}
    	return res;
    };
    while (q.size()) {
    	int x = q.front(); q.pop();
    	if (!st[x]) {
    		ans.push_back(dfs(x, 0) - 1);
    	}
    }
    std::sort(ans.begin(), ans.end());
    for (int x : ans) std::cout << x << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}

