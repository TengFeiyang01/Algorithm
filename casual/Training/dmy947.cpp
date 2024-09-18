#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 301000;

void solve() {
    int n, R, C, idx = 0, cnt = 0;
    std::cin >> n >> R >> C;
    std::map<std::pair<int, int>, int> id;
    std::map<int, std::vector<int>> r, c;
    std::vector<int> x(n), y(n), t(n);
    std::map<int, int> rid, cid;
    std::vector<int> dfn(N), low(N), ins(N), a(n), bel(N);
    std::vector<i64> dp(N);
    std::stack<int> stk;

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < n; ++i) {
    	std::cin >> x[i] >> y[i] >> t[i];
    	--x[i], --y[i];
    	id[{x[i], y[i]}] = i;
        r[x[i]].push_back(i);
        c[y[i]].push_back(i);
    }

    int tot = n - 1;
    for (int i = 0; i < n; ++i) {
    	if (t[i] == 1) {
            if (!rid.count(x[i])) {
                rid[x[i]] = ++tot;
                for (int v : r[x[i]])  {
                    adj[tot].push_back(v);
                }
            }
            adj[i].push_back(rid[x[i]]); 
    	} else if (t[i] == 2) {
            if (!cid.count(y[i])) {
                cid[y[i]] = ++tot;
                for (int v : c[y[i]]) {
                    adj[tot].push_back(v);
                }
            }
            adj[i].push_back(cid[y[i]]);
    	} else if (t[i] == 3) {
    		for (int dx : {-1, 0, 1}) {
    			for (int dy : {-1, 0, 1}) {
    				if (dx == 0 and dy == 0) continue;
    				if (!id.count({x[i] + dx, y[i] + dy})) continue;
    				adj[i].push_back(id[{x[i] + dx, y[i] + dy}]);
    			}
    		}
    	}
    }
    i64 ans = 0;

    std::function<void(int)> tarjan = [&](int u) {
        dfn[u] = low[u] = ++idx;
        stk.push(u);
        ins[u] = true;
        for (int &v : adj[u]) {
            if (!dfn[v]) {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            } else {
                if (ins[v]) {
                    low[u] = std::min(low[u], dfn[v]);
                }
            }
        }

        if (low[u] == dfn[u]) {
            int y;
            ++cnt;
            dp[cnt] = 0;
            int sz = 0;
            do {
                y = stk.top();
                stk.pop();
                bel[y] = cnt;
                sz += (y < n);
                ins[y] = false;
                for (int v : adj[y]) {
                    int ne = bel[v];
                    if (ne != cnt && ne != 0) {
                        dp[cnt] = std::max(dp[cnt], dp[ne]);
                    }
                }
            } while (y != u);
            dp[cnt] += sz;
            ans = std::max(ans, dp[cnt]);
        }
    };

    for (int i = 0; i < n; ++i) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}