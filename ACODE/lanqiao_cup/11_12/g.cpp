#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 100010;

long long n, m, sg[N][40], f[40];
int a[N];

// 博弈使用记忆化搜索 当前在i上次跳的是l

bool sg_dfs(int x, int l) {
	if (sg[x][l] != -1) return sg[x][l];
	for (int i = l + 1; i <= m; ++i) {
		int v = f[i];
		if (x - v >= 1 && a[x - v] > a[x]) {
			if (!sg_dfs(x - v, i)) {
				return sg[x][l] = true;
			}
		}
		if (x + v <= n && a[x + v] > a[x]) {
			if (!sg_dfs(x + v, i)) {
				return sg[x][l] = true;
			}
		}
	}
	return false;
}

void solve() {
	std::cin >> n;
	f[0] = 0, f[1] = 1, f[2] = 2;;
	for (int i = 3; ; ++i) {
		f[i] = f[i - 1] + f[i - 2];
		if (f[i] >= 100000) {
			m = i - 1;
			break;
		}
	}
	memset(sg, -1, sizeof(sg));
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
	}   

	for (int i = 1; i <= n; ++i) {
		if (!sg_dfs(i, 0)) {
			std::cout << "Little Qiao\n";
		} else {
			std::cout << "Little Lan\n";
		}
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
