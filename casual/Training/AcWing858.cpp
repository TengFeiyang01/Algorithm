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
const int N = 1e5 + 13;
int g[510][510];
int vis[510]{0};
int dist[510];
    int n, m;

int prim() {
	memset(dist, 0x3f, sizeof dist);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int t = -1;
		for (int j = 1; j <= n; ++j) {
			if (!vis[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		}
		if (i && dist[t] == inf) return inf;
		if (i) ans += dist[t];
		for (int j = 1; j <= n; ++j) 
			dist[j] = std::min(dist[j], g[t][j]);
		vis[t] = 1;
	}
	return ans;
}

void solve() {
    std::cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; ++i) {
    	int a, b, c;
    	std::cin >> a >> b >> c;
    	g[a][b] = g[b][a] = std::min(g[a][b], c);
    }
    int t = prim();
    if (t == inf) std::cout << "impossible";
    else {
    	std::cout << t;
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
