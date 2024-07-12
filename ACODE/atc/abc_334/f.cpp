#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::array<int, 3>> p(n + 2);
    std::cin >> p[0][0] >> p[0][1];
    for (int i = 1; i <= n; ++i) {
    	std::cin >> p[i][0] >> p[i][1];
    }

    p[n + 1] = p[0];
    p[n + 1][2] = inf;
    
    std::sort(p.begin(), p.end(), [&](auto x, auto y){
        return x[2] < y[2];
    });


    auto getDis = [&](int i, int j) -> double {
    	double dx = p[i][0] - p[j][0], dy = p[i][1] - p[j][1];
    	return sqrt(dx * dx + dy * dy);
    };

    double ans = 0;
    for (int i = 0; i < n; ++i) {
    	ans += getDis(i, i + 1);	
    }
    ans += getDis(n, 0);

    std::vector<double> dp(n + 1);
    dp[0] = 0;

    std::deque<int> q;
    q.push_back(0);
    for (int i = 1; i <= n; ++i) {
    	while (!q.empty() and i - q.front() > k) q.pop_front();
    	dp[i] = dp[q.front()] + getDis(0, i) + getDis(0, i + 1) - (i == n ? 0 : getDis(i, i + 1));
    	while (!q.empty() and dp[q.back()] >= dp[i]) q.pop_back();
    	q.push_back(i);
    }

    double mv = 1e18;
    for (int i = n - k; i <= n; ++i) {
    	mv = std::min(mv, dp[i]);
    }
    std::cout << std::fixed << std::setprecision(15) << ans + mv << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
