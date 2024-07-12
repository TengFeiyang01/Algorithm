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
/*
    https://atcoder.jp/contests/arc148/submissions/38529258

    提示 1：如果只有一盏灯 v 亮着，要使所有灯关闭，需要操作 v 和 v 的所有儿子，也就是 1 + child[v] 次，其中 child[v] 表示 v 的儿子个数。

    提示 2：如果 v 的儿子已经亮着，就不用操作儿子了；同样地，如果 p[v] 已经亮着，就不用操作 v 自己了。
*/
void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> p(n + 1);
    std::vector<int> child(n + 1);
    for (int i = 2; i <= n; ++i) {
    	int v;
    	std::cin >> p[i];
    	child[p[i]]++;
    }
    while (q--) {
    	int m, v;
    	std::cin >> m;
        std::map<int, int> has;
    	for (int i = 0; i < m; ++i) {
    		std::cin >> v;
    		has[v] = 1;
    	}
    	int ans = 0;

    	for (auto[v, _] : has) {
    		ans += child[v];
    		if (has[p[v]]) ans--;
    		else ans++;
    	}
    	std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
