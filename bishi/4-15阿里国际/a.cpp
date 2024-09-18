#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), cnt(2);
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i] & 1]++;
    }

    for (int i = 0; i < n; ++i) {
    	if (i) {
    		cnt[a[i - 1] & 1]--;
    	}
    	if (i + 1 < n ) {
    		cnt[a[i + 1] & 1]--;
    	}
    	cnt[a[i] & 1]--;
    	ans += cnt[a[i] & 1];
    	cnt[a[i] & 1]++;
    	if (i) {
    		cnt[a[i - 1] & 1]++;
    	}
    	if (i + 1 < n) {
    		cnt[a[i + 1] & 1]++;
    	}
    }
    std::cout << ans / 2 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
