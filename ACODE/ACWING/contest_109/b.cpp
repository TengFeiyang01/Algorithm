#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

const int dirs[] = {-1, 0, 1, 0, -1};
int st[2001][2001]{0};

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::queue<PII> q;

    for (int i = 0; i < k; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	q.push({x - 1, y - 1});
    	st[x - 1][y - 1] = 1;
    }
    int cnt = n * m - k;
    while (q.size()) {
    	auto [x, y] = q.front();
    	q.pop();
    	if (--cnt == 0) {
    		std::cout << 1 + x << " " << 1 + y << "\n";
    		return;
    	}
    	for (int i = 0; i < 4; ++i) {
    		int nx = x + dirs[i], ny = y + dirs[i + 1];
    		if (0 <= nx and nx < n and 0 <= ny and ny < m and !st[nx][ny]) {
    			q.push({nx, ny});
    			st[nx][ny] = 1;
    		}
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
