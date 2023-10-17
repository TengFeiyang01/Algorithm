#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int ans = 0;

    //从起点和终点出发 能k步走到的点是一个集合
    //使得每一步对应位置相等即可

    std::vector<std::vector<int>> cnt(110, std::vector<int>(2));
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		int x;
    		std::cin >> x;
    		cnt[i + j][x]++;
    	}
    }
    int len = m + n - 2;
    for (int i = 0, j = len; i < j; ++i, --j) {
    	ans += std::min({cnt[i][0] + cnt[j][0], cnt[i][1] + cnt[j][1]});
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
