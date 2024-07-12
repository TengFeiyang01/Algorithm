#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> last(n);
    std::vector<std::array<int, 3>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    	last[i] = i;
    }
    for (int i = 0; i < m; ++i) {
    	int u, v;
    	std::cin >> u >> v;
    	--u, --v;
    	last[v] = std::max(last[v], u);
    }


   	std::vector<std::array<int, 2>> prs(n);
   	for (int i = 0; i < n; ++i) prs[i] = {last[i], a[i][2]};
   	std::ranges::sort(prs);

    i64 ans = 0, j = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        while (k < a[i][0] && !pq.empty()) {
            auto val = pq.top();
            pq.pop();
            ans -= val;
            k++;
        }
        if (k < a[i][0]) {
            ans = -1;
            break;
        }
        k += a[i][1];
        while (j < n and prs[j][0] == i) {
            k--;
            ans += prs[j][1];
            pq.push(prs[j][1]);
            j++;
        }
    }
    while (k < 0 and !pq.empty()) {
        k++;
        ans -= pq.top();
        pq.pop();
    }
    std::cout << ans;

    /*
   	std::vector dp(n + 1, std::vector(5001, -inf));
   	for (int i = 0; i <= k; ++i) dp[0][i] = 0;
   	int now = 0;
   	for (int i = 0; i < n; ++i) {
   		for (int t = a[i][0]; t + a[i][1] <= 5000; ++t) {
   			dp[i + 1][t + a[i][1]] = std::max(dp[i + 1][t + a[i][1]], dp[i][t]);
   		}

   		while (now < n and prs[now][0] == i) {
   			for (int t = 0; t < 5000; ++t) {
   				dp[i + 1][t] = std::max(dp[i + 1][t], dp[i + 1][t + 1] + prs[now][1]);
   			}
   			now++;
   		}
   	}
   	int ans = -1;
   	for (int i = 0; i <= 5000; ++i) {
   		ans = std::max(dp[n][i], ans);
   	}
   	std::cout << ans << "\n";*/
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
