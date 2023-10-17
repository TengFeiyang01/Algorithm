#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

/*
脑筋急转弯。
    如果 # 个数小于 3，那么无法分成多个连通块，输出 -1。
    否则有解（注意原图是连通的）。
    对于角落的 #，可以把相邻的两个 # 改成 . 使得图不连通，所以至多操作 2 次。
    如果角落没有 #，一定存在一个边上的 # 至多有两个 . 邻居，所以也至多操作 2 次。
    那么只需要判断能否操作 1 次使图不连通。
    代码写的是 O(n^2m^2) 的暴力，可以用 Tarjan 割点做到 O(nm)。

    https://codeforces.com/contest/193/submission/215507875

    相似题目：2556. 二进制矩阵中翻转最多一次使路径不连通
*/


void solve() {
    int n, m;
    std::cin >> n >> m;
    int tot = 0;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> s[i];
    	tot += std::count(s[i].begin(), s[i].end(), '#');
    }
    if (tot < 3) {
    	std::cout << "-1\n";
    	return;
    } 
    int dirs4[] = {-1, 0, 1, 0, -1};
    std::vector st(n, std::vector<int>(m));
    int t = 0;

    int cnt = 0;
    auto dfs = [&](auto self, int x, int y) ->bool {
    	if (x < 0 or x >= n or y < 0 or y >= m or st[x][y] == t or s[x][y] != '#') return false;
    	st[x][y] = t;
    	cnt++;
    	for (int i = 0; i < 4; ++i) {
    		self(self, x + dirs4[i], y + dirs4[i + 1]);
    	}
    	return true;
    };

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (s[i][j] != '#') continue;
    		s[i][j] = '.';
    		t++;
    		cnt = 0;
    		for (int k = 0; k < 4; ++k) {
    			if (dfs(dfs, i + dirs4[k], j + dirs4[k + 1])) break;
    		}
    		if (cnt < tot - 1) {
    			std::cout << "1\n";
    			return;
    		}
    		s[i][j] = '#';
    	}
    }
    std::cout << "2\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
