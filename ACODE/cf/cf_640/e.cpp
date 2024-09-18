#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 8001;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), cnt(n + 1);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	b[i] = a[i];
    	if (i) b[i] += b[i - 1];
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = i + 1; j < n; ++j) {
    		int s;
    		if (i == 0) {
    			s = b[j];
    		} else {
    			s = b[j] - b[i - 1];
    		}
    		if (s <= n) cnt[s]++;
    	}
    }
    int ans = 0;

    for (int i = 0; i < n; ++i) {
    	if (cnt[a[i]]) {
    		ans++;
    	}
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