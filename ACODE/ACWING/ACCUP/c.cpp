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

const int dir[] = {-1, 0, 1, 0, -1};
int dist[N][N];

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int x1, x2, y1, y2;
    std::string g[n];
    for (int i = 0; i < n; ++i) std::cin >> g[i];
	
	std::cin >> x1 >> y1 >> x2 >> y2;
    x1--, x2--, y1--, y2--;

	int cnt = 0;
    std::queue<PII> q;
    q.push({x1, y1});
	memset(dist, inf, sizeof dist);

    dist[x1][y1] = 0;
    while (q.size()) {
    	auto[s, t] = q.front();
    	q.pop();
    	for (int i = 0; i < 4; ++i) {
    		int nx = s, ny = t, nd = dist[s][t] + 1;
    		for (int j = 1; j <= k; ++j) {
    			nx += dir[i];
    			ny += dir[i + 1];
    			if (nx < 0 or ny < 0 or nx >= n or ny >= m) break;
    			if (g[nx][ny] == '#' or dist[nx][ny] < nd) {
    				break;
    			}
    			if (dist[nx][ny] > nd) {
    			    dist[nx][ny] = nd;
    				q.push({nx, ny});	
    			}
    		}
    	}
    }
    if (dist[x2][y2] == inf) {
    	std::cout << "-1\n";
    } else {
    	std::cout << dist[x2][y2];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
