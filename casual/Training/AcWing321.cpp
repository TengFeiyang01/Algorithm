#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 15, M = 10;

int n, m = 8;
int s[M][M]{0};
double f[M][M][M][M][N];
const double INF = 1e9;
double X;

double get(int x1, int y1, int x2, int y2) {
	double sum = s[x2][y2] + s[x1 - 1][y1 - 1] - s[x1 - 1][y2] - s[x2][y1 - 1] - X;
	return (double)sum * sum / n;
}

double dp(int x1, int y1, int x2, int y2, int k) {

	double &v = f[x1][y1][x2][y2][k];
	if (v >= 0) return v;
	if (k == 1) return v = get(x1, y1, x2, y2);

	v = INF;

	for (int i = x1 + 1; i < x2; ++i) {
		v = std::min(v, dp(x1, y1, i, y2, k - 1) + get(i + 1, y1, x2, y2));
		v = std::min(v, dp(i + 1, y1, x2, y2, k - 1) + get(x1, y1, i, y2));
	}

	for (int i = y1 + 1; i < y2; ++i) {
		v = std::min(v, dp(x1, y1, x2, i, k - 1) + get(x1, i + 1, x2, y2));
		v = std::min(v, dp(x1, i + 1, x2, y2, k - 1) + get(x1, y1, x2, i));
	}
	return v;
}

void solve() {
    std::cin >> n;
    for (int i = 1; i <= m; ++i)
    	for (int j = 1; j <= m; ++j) {
    		std::cin >> s[i][j];
    		s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    	}
    memset(f, -1, sizeof f);
    X = (double)s[m][m] / n;

    printf("%.3lf", sqrt(dp(1, 1, 8, 8, n)));
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
