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
const int N = 1e3 + 13;
int g[N][N], st[N][N]{0};
int n, m;
PII q[N * N];
bool has_highter = false, has_lower = false;


int bfs(int sx, int sy) {
	int hh = 0, tt = 0;
	q[0] = {sx, sy};
	st[sx][sy] = true;
	while (hh <= tt) {
		auto[x, y] = q[hh++];
		for (int i = x - 1; i <= x + 1; ++i)
			for (int j = y - 1; j <= y + 1; ++j) {
				if (i < 0 || i >= n || j < 0 || j >= m) continue;
				if (g[i][j] != g[x][y]) {
					if (g[i][j] > g[x][y]) has_highter = true;
					else has_lower = true;
				} else if (!st[i][j]) {
					q[++tt] = {i, j};
					st[i][j] = true;
				}
			}
	}	
}

void solve() {
    std::cin >> n;
    m = n;
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j)
    		std::cin >> g[i][j];
    	
    int up = 0, down = 0;
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < m; ++j)
    		if (!st[i][j]) {
    			has_lower = has_highter = false;
    			int t = bfs(i, j);
    			if (!has_highter) up++;
    			if (!has_lower) down++;
    		}
    std::cout << up << " " << down;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
