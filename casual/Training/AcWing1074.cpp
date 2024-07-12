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
const int N = 1e2 + 13;


/*void dfs(int u, int fa) {
	for (auto[v, w] : g[u]) {
		if (v == fa) continue;
		dfs(v, u);
		for (int j = m; j >= 0; --j)
			for (int k = 0; k < j; ++k)
				f[u][j] = std::max(f[u][j], f[u][j - k - 1] + f[v][k] + w);
	}
}
*/
void solve() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<PII>> g(n);
    vector f(n, std::vector<int>(m + 1));
	for (int i = 1; i < n; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;
		a--, b--;
		g[a].eb(b, c);
		g[b].eb(a, c);
	}
    
    //须带返回值
    auto dfs = [&](auto&& self, int u, int fa) ->int {
        for (auto[v, w] : g[u]) {
            if (v == fa) continue;
            self(self, v, u);
            for (int j = m; j >= 0; --j)
                for (int k = 0; k < j; ++k)
                    f[u][j] =std::max(f[u][j], f[u][j - k - 1] + f[v][k] + w);
        }  
        return 0;
    };

	//dfs(0, -1);
    
    dfs(dfs, 0, -1);
    
	std::cout << f[0][m] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}