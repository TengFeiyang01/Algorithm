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
const int N = 500 + 13;
std::vector<int> dist(N, inf);
int g[N][N];
int n, m;
int vis[N]{0};

int dijkstra() {
	dist[1] = 0;
	for (int i = 1; i <= n; ++i) {
		int t = -1;
		for (int j = 1; j <= n; ++j)
			if (!vis[j] && (t == -1 || dist[t] > dist[j])) 
				t = j;
		if (t == n) break;
		vis[t] = 1;
		for (int j = 1; j <= n; ++j)
			dist[j] = std::min(dist[j], dist[t] + g[t][j]);
	}
	if (dist[n] == inf) return -1;

	return dist[n];
}

void solve() {
    std::cin >> n >> m;
	memset(g, inf, sizeof g);    
    for (int i = 0; i < m; ++i) {
    	int u, v, w;
    	std::cin >> u >> v >> w;
    	g[u][v] = std::min(g[u][v], w);
    }
   	std::cout << dijkstra();
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
