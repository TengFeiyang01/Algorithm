#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n, m, k, w;
	std::cin >> n >> m >> k >> w;
	std::vector<int> a(w);
    i64 ans = 0;
    std::vector d(n + 2, std::vector(m + 2, 0));
    
    for (int &x : a) {
        std::cin >> x;
    }
    
    for (int i = 1; i + k - 1 <= n; ++i) {
    	for (int j = 1; j + k - 1 <= m; ++j) {
    		int p = i + k, q = j + k;
    		d[i][j]++;
    		d[p][q]++;
    		d[i][q]--;
    		d[p][j]--;
    	}
    }
    std::vector<int> pq;
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= m; ++j) {
    		d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
    		pq.push_back(d[i][j]);
    	}
    }
    std::ranges::sort(pq, std::greater());
    std::ranges::sort(a, std::greater());
    for (int i = 0; i < w; ++i) {
        ans += 1ll * a[i] * pq[i]; 
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
	