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
const int N = 13 + 13;

int n, m;
std::set<int> ans;
int g[N][N];
int res = 0;
std::vector<PII> q{{1, 0}, {0, 1}};
void dfs(int i, int j) {
	if (i == n && j == m) {
		ans.insert(g[i][j]);
		if (ans.size() == n + m - 1) res++;
		return;
	}
	if (i + 1 <= n && ans.find(g[i + 1][j]) == ans.end()) {
		ans.insert(g[i + 1][j]);
		dfs(i + 1, j);
		ans.erase(g[i + 1][j]);
	}
	if (j + 1 <= m && ans.find(g[i][j + 1]) == ans.end()) {
		ans.insert(g[i][j + 1]);
		dfs(i, j + 1);
		ans.erase(g[i][j + 1]);
	}
}


void solve() {
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= m; ++j)
    		std::cin >> g[i][j];
    ans.insert(g[1][1]);
    dfs(1, 1);
    std::cout << res;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
