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
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < 2; ++i)
    	for (int j = 0; j < n; ++j)
    		std::cin >> a[j][i];
    //O(n^2)
    i64 ans = 1e14;
    for (int i = 1; i < n - 1; ++i) {
    	int b = inf, c = inf;
    	for (int j = 0; j < i; ++j) {
    		if (a[j][0] < a[i][0]) {
                b = std::min(b, a[j][1]);
            }
    	}
    	for (int j = i + 1; j < n; ++j) {
    		if (a[j][0] > a[i][0]) c = std::min(c, a[j][1]);
    	}
    	if (inf == c or b == inf) continue;
    	else ans = std::min(ans, a[i][1] + b + c + 0LL);
    }
    //线段树优化到nlogn(查找当前区间左侧的最小值，右侧的最小值)
    std::cout << (ans == 1e14 ? -1 : ans) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
