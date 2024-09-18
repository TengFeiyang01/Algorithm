#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> s(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> s[i];
    	s[i] += s[i - 1];
    }
    // 切的顺序与最终答案无关

    std::vector<i64> dp(n + 1), q(n + 2);
    int hh = 1, tt = 1;
    auto slope = [&](int i, int j) {
        if (s[i] == s[j]) return -1e18;
        return 1.0 * ((dp[i] - s[i] * s[i]) - (dp[j] - s[j] * s[j])) / (s[j] - s[i]);
    };
    std::vector pre(n + 1, std::vector<int>(k + 1));

    // dp[i] = dp[l] + s[l] * (s[i] - s[l])
    // 斜率 k = s[i] 是定制 且单调不减
    // 记为过 (-s[l], dp[l] - s[l] * s[l]) 的直线 截距为 dp[l] - s[l] * s[l] 最大值为斜率最大时的点
    // 若有 j k两点
    // 当选 j 比选 k 更优秀时
    // dp[k] - s[k] * s[k] + s[i] * s[k] < dp[j] - s[j] * s[j] + s[i] * s[j]
    // dp[j] - s[j] * s[j] - (dp[k] - s[k] * s[k]) > s[i] * (s[k] - s[j])
    // (dp[j] - s[j] * s[j]) - (dp[k] - s[k] * s[k]) / (-s[j] - (-s[k])) > s[i] 
    // 故单调队列维护一个点集 斜率递增
    for (int j = 1; j <= k; ++j) {
    	int hh = 0, tt = 0;
    	q[++tt] = 0;
        std::vector<i64> ndp(n + 1);
    	for (int i = 1; i <= n; ++i) {
    		while (hh < tt and slope(q[hh], q[hh + 1]) <= s[i]) ++hh;
    		ndp[i] = dp[q[hh]] + s[q[hh]] * (s[i] - s[q[hh]]);
    		pre[i][j] = q[hh];
    		while (hh < tt and slope(q[tt - 1], q[tt]) >= slope(q[tt], i)) --tt;
    		q[++tt] = i;
    	}
    	dp.swap(ndp);
    }
    std::cout << dp[n] << "\n";
    for (int x = n, i = k; i; --i) {
    	x = pre[x][i];
    	std::cout << x << " \n"[i == 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
