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
const int N = 20;
int n;
bool col[N], dg[N], udg[N];
char g[N][N];

void dfs(int u) {
	if (u == n) {
		for (int i = 0; i < n; ++i) puts(g[i]);
		puts("");
		return;
	}
	for (int i = 0; i < n; ++i) 
		if (!col[i] && !dg[u + i] && !udg[n + i - u]) {
			g[u][i] = 'Q';
			col[i] = udg[n + i - u] = dg[u + i] = true;
			dfs(u + 1);
			col[i] = udg[n + i - u] = dg[u + i] = false;
			g[u][i] = '.';
		}
}

void solve() {
	std::cin >> n;
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            g[i][j] = '.';    
	dfs(0);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
