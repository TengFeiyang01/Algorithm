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

//拐点只能偶数个位置
//端点同理 他们都可以走到同样奇偶性的位置
//两个端点是可以到达任意位置的奇偶性相同的点

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> xs, ys;
    for (int i = 0; i < 3; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	xs[x]++;
    	ys[y]++;
    }
	int tx, ty;
	std::cin >> tx >> ty;
	int sx, sy;
	for (auto &[x, c] : xs) {
		if (c == 2) {
			sx = x;
		}
	}
	for (auto &[y, c] : ys) {
		if (c == 2) {
			sy = y;
		}
	}

	if ((sx == 1 or sx == n) and (sy == 1 or sy == n)) {
		if (tx == sx or ty == sy) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
		return;
	}

	//计算的是L的两个端点
	if ((tx - sx + ty - sy) & 1) {
		std::cout << "YES\n";
		return;
	}
	if ((tx - sx) % 2 == 0 or (ty - sy) % 2 == 0) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
