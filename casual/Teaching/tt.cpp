#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

int dp[20][20][4];

struct node {
	int x, y, p;
};

int dirs[] = {-1, 0, 1, 0, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;
    memset(dp, 127, sizeof(dp));

    std::vector<std::string> s(n);
   	
   	std::queue<node> q;
   	node st;

    for (int i = 0; i < n; ++i) {
    	std::cin >> s[i];
    	for (int j = 0; j < m; ++j) {
    		if (s[i][j] == 'B') {
    			q.push(node{i, j, 0});
    			st = node{i, j, 0};
    		}
    	}
    }
    int ans = inf;
    dp[st.x][st.y][st.p] = 0;
    while (!q.empty()) {
    	auto [x, y, p] = q.front();
    	q.pop();
    	if (s[x][y] == '*') {
    		ans = std::min(ans, dp[x][y][p] + p);
    	}

    	for (int k = 0; k < 4; ++k) {
    		int nx = x + dirs[k], ny = y + dirs[k + 1];
    		if (0 <= nx and nx < n and 0 <= ny and ny < m) {
    			int np = p + (s[nx][ny] == 'W');
    			if (np > 3) continue;
    			if (dp[nx][ny][np] > dp[x][y][p] + 1) {
    				dp[nx][ny][np] = dp[x][y][p] + 1;
    				q.push(node{nx, ny, np});
    			}
    		}
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
