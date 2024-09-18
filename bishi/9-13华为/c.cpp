#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

int dirs[] = {-1, 0, 1, 0, -1};

void solve() {
	int p, n, m;
	std::cin >> p;
	std::cin >> n >> m;
	std::vector<std::vector<int>> g(n, std::vector<int>(m));
	std::vector<std::vector<int>> pre(n, std::vector<int>(m, 0));
	int sx, sy, tx, ty;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::string s;
			std::cin >> s;
			if (s == "s") {
				sx = i;
				sy = j;
				g[i][j] = p;
			} else if (s == "t") {
				tx = i;
				ty = j;
				g[i][j] = inf;
			} else {
				g[i][j] = stoi(s);
			}
		}
	}

	std::queue<std::pair<int, int>> q;
	q.push({sx * m + sy, p});
	std::set<int> st;
	st.insert(sx * m + sy);
	int ok = 0;
	while (q.size()) {
		auto t = q.front();
		q.pop();
		int i = t.first / m, j = t.first % m, h = t.second;
		if (i == tx and j == ty) {
			ok = 1;
		}
		for (int k = 0; k < 4; ++k) {
			int x = i + dirs[k], y = j + dirs[k + 1], nh = h + 1;
			if (0 <= x and x < n and 0 <= y and y < m and g[x][y] > nh and !st.count(x * m + y)) {
				pre[x][y] = i * m + j;
				st.insert(x * m + y);
				q.push({x * m + y, nh});
			}
		}
	}
	std::vector<std::string> ans;
	if (ok) {
		ans.push_back("t");
		int x = tx, y = ty;
		while (x * m + y != sx * m + sy) {
			int cx = pre[x][y] / m, cy = pre[x][y] % m;
			if (cx == sx and cy == sy) {
				ans.push_back("s");
			} else {
				ans.push_back(std::to_string(g[cx][cy]));
			}
			x = cx;
			y = cy;
		}
		std::reverse(ans.begin(), ans.end());
		m = ans.size();
		for (int i = 0; i < m; ++i) {
			std::cout << ans[i] << " \n"[i == m - 1];
		}
	} else {
		std::cout << "s";
	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
