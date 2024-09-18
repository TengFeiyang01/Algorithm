#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

int dirs[] = {-1, 0, 1, 0, -1};

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> s(n);
    int sx = -1, sy = -1, tx = -1, ty = -1, ex = -1, ey = -1;

    std::vector<std::array<int, 2>> points;

    for (int i = 0; i < n; ++i) {
    	std::cin >> s[i];
    	for (int j = 0; j < m; ++j) {
    		if (s[i][j] == 'S') {
    			sx = i;
    			sy = j;
    		} else if (s[i][j] == 'T') {
    			s[i][j] = '#';
    			tx = i;
    			ty = j;
    		} else if (s[i][j] == 'E') {
    			ex = i;
    			ey = j;
    		}
    	}
    }
    points.push_back({sx, sy});

 	for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (s[i][j] == '$') {
    			points.push_back({i, j});
    		}
    		if (abs(i - tx) + abs(j - ty) <= k) {
    			s[i][j] = '#';
    		}
    	}
    	std::cout << "\n";
    }
    points.push_back({ex, ey});


    std::vector<std::vector<int>> dist(9, std::vector<int>(9, inf));

    for (int i = 0; i < 9; ++i) {
    	std::queue<int> q;
    	std::vector<std::vector<int>> d(n, std::vector<int>(m, inf));

    	q.push(points[i][0] * m + points[i][1]);
    	d[points[i][0]][points[i][1]] = 0;

    	while (q.size()) {
    		int t = q.front();
    		q.pop();

    		int x = t / m, y = t % m;
    		for (int j = 0; j < 9; ++j) {
    			if (x == points[j][0] and y == points[j][1]) {
    				dist[i][j] = d[x][y];
    			}
    		}

    		for (int k = 0; k < 4; ++k) {
    			int a = x + dirs[k], b = y + dirs[k + 1];
    			if (0 <= a and a < n and 0 <= b and b < m and s[a][b] != '#' and d[a][b] == inf) {
    				d[a][b] = d[x][y] + 1;
    				q.push(a * m + b);
    			}
    		}
    	}
    }

	int comb = (1 << 5) - 1, res = inf;

	while (comb < 1 << 7) {
		std::vector<int> p;
		for (int i = 0; i < 7; ++i) {
			if (comb >> i & 1) {
				p.push_back(i + 1);
			}
		}
		do {
			int ans = 0;
			ans += dist[0][p[0]];
			ans += dist[p.back()][8];
			for (int i = 1; i < p.size(); ++i) {
				ans += dist[p[i - 1]][p[i]];
			}
			res = std::min(res, ans);
		} while (std::next_permutation(p.begin(), p.end()));

		int x = comb & -comb, y = comb + x;
		comb = ((comb&~y) / x >> 1) | y;
	}
	if (res == inf) {
		res = -1;
	}
	std::cout << res << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
