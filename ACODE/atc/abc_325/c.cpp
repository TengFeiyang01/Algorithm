#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int H, W;
	std::cin >> H >> W;

	std::vector<std::string> s(H);
	for (int i = 0; i < H; ++i) {
		std::cin >> s[i];
	}

	int ans = 0;
	auto dfs = [&](auto &&self, int x, int y) ->void {
		if (0 <= x and x < H and 0 <= y and y <= W and s[x][y] == '#') {
			s[x][y] = '.';
			for (auto dx : {-1, 0, 1}) {
				for (auto dy : {-1, 0, 1}) {
					if (dx or dy) {
						self(self, x + dx, y + dy);
					}
				}
			}
		} else {
			return;
		}
	};

	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (s[i][j] == '#') {
				dfs(dfs, i, j);
				ans++;
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