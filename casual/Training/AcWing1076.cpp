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

void solve() {
	int n;
	std::cin >> n;
	int g[n][n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			std::cin >> g[i][j];
	PII pre[n][n];
	PII end(0, 0);

	std::queue<PII> q;
	q.push({n - 1, n - 1});
	
	memset(pre, -1, sizeof pre);

	int dirs[] = {-1, 0, 1, 0, -1};

	while (q.size()) {
		auto[x, y] = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dirs[i], ny = y + dirs[i + 1];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || g[nx][ny]) continue;
			if (pre[nx][ny].first != -1) continue;
			pre[nx][ny] = {x, y};
			q.push({nx, ny});
		}
	}

	while (1) {
		auto[x, y] = end;
		std::cout << x << " " << y << "\n";
		end = pre[x][y];
		if (x == n - 1 && y == n - 1) break;
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
