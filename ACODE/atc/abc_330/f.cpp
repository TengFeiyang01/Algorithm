#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	i64 N, K;
	std::cin >> N >> K;
	std::vector<i64> X(N), Y(N), preX(N), sufX(N), preY(N), sufY(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> X[i] >> Y[i];
	}
	std::ranges::sort(X);
	std::ranges::sort(Y);

	i64 sx = 0, sy = 0;
	for (int i = 0; i < N; ++i) {
		preX[i] = i * X[i] - sx;
		sx += X[i];
		preY[i] = i * Y[i] - sy;
		sy += Y[i];
	}
	sx = 0, sy = 0;
	for (int i = N - 1, j = 0; i >= 0; --i, ++j) {
		sufX[i] = sx - j * X[i];
		sx += X[i];
		sufY[i] = sy - j * Y[i];
		sy += Y[i];
	}
	
	
	auto check = [&](i64 x) ->bool {
		i64 res1 = 1e18, res2 = 1e18;
		int i = 0, j = 0;
		while (j < N) {
			j = std::ranges::upper_bound(X, X[i] + x) - X.begin();
			res1 = std::min(res1, preX[i] + sufX[j - 1]);
			i++;
		}

		i = 0, j = 0;
		while (j < N) {
			j = std::ranges::upper_bound(Y, Y[i] + x) - Y.begin();
			res2 = std::min(res2, preY[i] + sufY[j - 1]);
			i++;
		}
		return res1 + res2 <= K;
	};

	i64 l = 1, r = 1e15;
	while (l < r) {
		i64 mid = l + r >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
