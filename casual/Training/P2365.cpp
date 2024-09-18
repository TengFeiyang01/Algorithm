#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n, s;
    std::cin >> n >> s;
    std::vector<i64> t(n + 1), f(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> t[i] >> f[i];
    	t[i] += t[i - 1];
    	f[i] += f[i - 1];
    }

    std::vector<i64> dp(n + 1, 1E18);
    dp[0] = 0;

    /*
    for (int i = 1; i <= n; ++i) {
    	for (int j = 0; j < i; ++j) {
            //每次分组 会使得j之后的所有的任务多计算一次 s  处理后效性
    		dp[i] = std::min(dp[i] * 1LL, 1LL * dp[j] + t[i] * (f[i] - f[j]) + s * (f[n] - f[j]));
    	}
    }
    */
    //dp[i] = dp[j] + t[i] * (f[i] - f[j]) + s * (f[n] - f[j])
    //dp[i] = -f[j] * (s + t[i]) + dp[j] + t[i] * f[i] + s * f[n]
    //dp[j] = dp[i] - t[i] * f[i] - s * f[n] + f[j] * (s + t[i])
    //y = dp[j]  b = dp[i] - t[i] * f[i] - s * f[n]  k = s + t[i] x = f[j]
    //要让y最小 k是定值 即b最小

    std::vector<int> q(n + 1);
    int hh = 1, tt = 1;
    for (int i = 1; i <= n; ++i) {
        //队头过期出队  y1 - y2 <= k * (x1 - x2)  保证决策点左侧小于当前斜率的出队
        while (hh < tt and dp[q[hh + 1]] - dp[q[hh]] <= (s + t[i]) * (f[q[hh + 1]] - f[q[hh]])) hh++;
        dp[i] = dp[q[hh]] + t[i] * f[i] + s * f[n] - f[q[hh]] * (s + t[i]);
        //当前点以及队尾点的斜率是递增应该
        while (hh < tt and (dp[i] - dp[q[tt]]) * (f[q[tt]] - f[q[tt - 1]]) <= (dp[q[tt]] - dp[q[tt - 1]]) * (f[i] - f[q[tt]])) tt--;
        q[++tt] = i;
    }    


    std::cout << dp[n] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
