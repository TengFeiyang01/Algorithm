#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::string s[8];
    for (int i = 0; i < 8; ++i) std::cin >> s[i];
    int x = -1, y = -1;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (x == -1 and s[i][j] != '.') {
				x = i;
				y = j;
			}
		}
	}
	int dir[] = {-1, 0, 1, 0, -1};
	std::queue<PII> q;
	q.push({x, y});
	std::string ans = "";
	while (q.size()) {
		auto[a, b] = q.front();
		q.pop();
		ans += s[a][b];
		s[a][b] = '.';
		for (int i = 0; i < 4; ++i) {
			int nx = a + dir[i], ny = b + dir[i + 1];
			if (nx >= 8 or ny >= 8 or nx < 0 or ny < 0 or s[nx][ny] == '.') continue;
			q.push({nx, ny});
		}
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
