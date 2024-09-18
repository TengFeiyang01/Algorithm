#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

/*
	https://codeforces.com/problemset/problem/883/I

	输入 n k(1≤k≤n≤3e5) 和长为 n 的数组 a(1≤a[i]≤1e9)。

	把这 n 个数重新排列，然后分成若干个组，要求每组至少有 k 个数。
	定义 diff(b) 表示序列 b 中最大值与最小值的差。
	计算所有组的 diff 值的最大值 mx。
	输出 mx 的最小值。

*/

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}    
	std::sort(a.begin(), a.end());
	
	auto check = [&](int x) ->bool {
		std::vector<bool> f(n + 1, false);
		f[0] = true;
		int j0 = 0;
		for (int i = k - 1; i < n; ++i) {
			while (a[i] - a[j0] > x) {
				j0++;
			}
			while (j0 <= i - k + 1) {
				if (f[j0]) {
					f[i + 1] = true;
					break;
				}
				j0++;
			}
		}
		return f[n];
	};


	int l = 0, r = a[n - 1] - a[0];
	while (l < r) {
		int mid = l + r >> 1;
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
