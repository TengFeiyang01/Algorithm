#include <bits/stdc++.h>
 
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

// https://codeforces.com/problemset/problem/219/D

// 输入 n(2≤n≤2e5) 和 n-1 条边 v w，表示一条 v->w 的有向边。（节点编号从 1 开始）
// 保证输入构成一棵树。

// 定义 f(x) 表示以 x 为根时，要让 x 能够到达任意点，需要反向的边的数量。
// 输出 min(f(x))，以及所有等于 min(f(x)) 的节点编号（按升序输出）。

// 换根dp
// 先把以 1 为根的答案求出来。
// 从 v 换到 w 时，如果有 v->w，那么答案加一，否则答案减一。


void solve() {
    int n, cnt1 = 0, u, v;
    std::cin >> n;
    std::vector<PII> adj[n + 1];
    for (int i = 1; i < n; ++i) {
    	std::cin >> u >> v;
    	adj[u].emplace_back(v, 1);
    	adj[v].emplace_back(u, -1);
    }
    std::function<void(int, int)> dfs1 = [&](int u, int fa) {
    	for (auto&[v, w] : adj[u]) {
    		if (v != fa) {
                if (w < 0) cnt1++;
    			dfs1(v, u);
    		}
    	}
    };
    dfs1(1, 0);

    int mn = cnt1;
    std::vector<int> ans;
    std::function<void(int, int, int)> dfs2 = [&](int u, int fa, int cnt) {
    	if (cnt < mn) {
    		mn = cnt;
    		ans = {u};
    	} else if (cnt == mn) {
    		ans.emplace_back(u);
    	}
    	for (auto&[v, w] : adj[u]) {
    		if (v != fa) {
    			dfs2(v, u, cnt + w);
    		}
    	}
    };
    dfs2(1, 0, cnt1);

    std::cout << mn << "\n";
    std::sort(all(ans));
    for (int i = 0; i < sz(ans); ++i) {
    	std::cout << ans[i] << " \n"[i == sz(ans) - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
