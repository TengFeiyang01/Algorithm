#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, root = 0, cnt = 0;
    std::cin >> n;
    std::vector<int> a(n + 1), l(n + 1, 0), r(n + 1, 0);
    std::stack<int> stk;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	int last = 0;
    	while (stk.size() and a[stk.top()] > a[i]) {
    		last = stk.top();
    		stk.pop();
    	}
    	if (!stk.empty()) r[stk.top()] = i;
    	else root = i;
    	l[i] = last;
    	stk.push(i);
    }

    std::vector<int> ans(n + 1);
    std::function<void(int)> dfs = [&](int u) {
    	ans[u] = ++cnt;
    	if (l[u]) dfs(l[u]);
    	if (r[u]) dfs(r[u]);
    };

    dfs(root);
    for (int i = 1; i <= n; ++i) {
    	std::cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
