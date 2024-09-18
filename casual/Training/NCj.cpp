#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int dir[] = {-1, 0, 1, 0, -1};

void solve() {
    int n, m, sx, sy;
    std::cin >> n >> m >> sx >> sy;
    --sx, --sy;
    std::vector a(n, std::vector<i64>(m, 0));
    std::vector st(n, std::vector<bool>(m, false));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		std::cin >> a[i][j];
    	}
    }
    struct node {
    	i64 x, y, z;
    	bool operator<(const node &other) const {
    		return z > other.z;
    	}
    };
    std::priority_queue<node> pq;

    st[sx][sy] = true;
    pq.push({sx, sy, a[sx][sy]});
    i64 ans = 0, now = 0;

    while (!pq.empty()) {
    	auto [x, y, v] = pq.top();
    	pq.pop();
    	if (v > now) {
    		ans += v - now;
            // 确定起点不吃两次
    		if (x != sx || y != sy) {
    			now = v;
    		}
    	}
    	now += v;
    	for (int i = 0; i < 4; ++i) {
    		int nx = x + dir[i], ny = y + dir[i + 1];
    		if (0 <= nx and nx < n and 0 <= ny and ny < m and !st[nx][ny]) {
    			st[nx][ny] = 1;
    			pq.push({nx, ny, a[nx][ny]});
    		}
    	}
    }
    if (ans != a[sx][sy]) {
    	std::cout << ans << "\n";
    } else {
    	std::cout << "No cheating need.";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
