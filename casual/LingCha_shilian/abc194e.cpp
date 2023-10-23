#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), cnt(n + 1);

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (i < m) cnt[a[i]]++;
    }
    int ans = 0;
    while (cnt[ans] > 0) ans++;
    for (int w, i = m; i < n; ++i) {
    	cnt[a[i]]++;
    	w = a[i - m];
    	cnt[w]--;
    	if (cnt[w] == 0 and w < ans) {
    		ans = w;
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}