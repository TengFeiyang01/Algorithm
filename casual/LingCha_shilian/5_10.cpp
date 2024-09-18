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
https://codeforces.com/problemset/problem/1118/D2

输入 n(1≤n≤2e5) (1≤m≤1e9) 和长为 n 的数组 a(1≤a[i]≤1e9)。

把这 n 个数重新排列，然后分成 x 个组。
每个组的第一个数不变，第二个数减一，第三个数减二，依此类推。
如果有数字减成负数，则从组中去掉。

要使所有数字之和至少为 m，x 最小是多少？
如果无法做到，输出 -1。
*/

void solve() {
    ll n, m, s = 0;
    std::cin >> n >> m;
    std::vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	s += a[i];
    }

	std::sort(a.rbegin(), a.rend());
	
	//m是最多能减少的量
	m = s - m;
	
	auto check = [&](int x) {
		ll dif = 0, t = 0;
		//前x个跳过
		for (int i = x; i < n; ++i) {
			if (i % x == 0) t++;
			dif += std::min(a[i], t);
		}
		return dif <= m;
	};

	int l = 1, r = n + 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if (l > n) {
		std::cout << "-1\n";
	} else {
		std::cout << l << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
