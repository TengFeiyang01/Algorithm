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
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
const double eps = 1e-6;


void solve() {
    int n;
    std::cin >> n;
    std::vector a(n, std::vector<double>(n + 1));
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j <= n; ++j)
    		std::cin >> a[i][j];

	auto gauss = [&]() ->int {
		int c, r;
		for (c = 0, r = 0; c < n; ++c) {// c 代表 列 col ， r 代表 行 row
			int t = r;
			for (int i = r; i < n; ++i)// 先找到当前这一列，绝对值最大的一个数字所在的行号
				if (fabs(a[i][c]) > fabs(a[t][c])) t = i;
			if (fabs(a[t][c]) < eps) continue;// 如果当前这一列的最大数都是 0 ，那么所有数都是 0，就没必要去算了，因为它的约束方程，可能在上面几行

			for (int i = c; i <= n; ++i) std::swap(a[t][i], a[r][i]);// 把当前这一行，换到最上面（不是第一行，是第 r 行）去
			for (int i = n; i >= c; --i) a[r][i] /= a[r][c];// 把当前这一行的第一个数，变成 1， 方程两边同时除以 第一个数，必须要到着算，不然第一个数直接变1，系数就被篡改，后面的数字没法算

			for (int i = r + 1; i < n; ++i)// 把当前列下面的所有数，全部消成 0
				if (fabs(a[i][c]) > eps) // 如果非0 再操作，已经是 0就没必要操作了
					for (int j = n; j >= c; --j)// 从后往前，当前行的每个数字，都减去对应列 * 行首非0的数字，这样就能保证第一个数字是 a[i][0] -= 1*a[i][0];
						a[i][j] -= a[r][j] * a[i][c];
			++r;
		}
		if (r < n) {
			for (int i = r; i < n; ++i)
				if (fabs(a[i][n]) > eps)
					return 2;//无解
			return 1;//无穷解
		}
		for (int i = n - 1; i >= 0; --i)
			for (int j = i + 1; j < n; ++j)
				a[i][n] -= a[i][j] * a[j][n];

		return 0;//唯一解
	};


    int t = gauss();
    if (!t) {
		for (int i = 0; i < n; ++i)
			printf("%.2lf\n", a[i][n] < eps ? 0 : a[i][n]);
    } else if (t == 1) puts("Infinite group solutions");
    else puts("No solution");
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
