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
const int N = 1e5 + 13;

int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};


void solve() {
    int n, m;
    std::cin >> m >> n;
    std::string g[n];
    PII start, ed;
    int st[n][m], d[n][m];
    memset(st, 0, sizeof st);
    memset(d, 0, sizeof d);
 
    for (int i = 0; i < n; ++i) {
    	std::cin >> g[i];
    	if (g[i].find('K') != -1) {
    		start = {i, g[i].find('K')};
    	}
    	if (g[i].find('H') != -1) {
    		ed = {i, g[i].find('H')};
    	}
    }

    std::queue<PII> q;
    q.push(start);
    auto[x, y] = start;
    st[x][y] = 1;

    while (q.size()) {
    	auto[x, y] = q.front(); q.pop();
    	if (x == ed.first && y == ed.second) break;
    	for (int i = 0; i < 8; ++i) {
    		int nx = x + dx[i], ny = y + dy[i];
    		if (nx < 0 || ny < 0 || nx >= n || ny >= m || g[nx][ny] == '*' || st[nx][ny]) continue;
    		q.push({nx, ny});
    		st[nx][ny] = 1;
    		d[nx][ny] = d[x][y] + 1;
    	}
    }

    std::cout << d[ed.first][ed.second];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
