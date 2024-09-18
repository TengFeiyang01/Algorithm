#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	int j = i + 1;
    	while (j < n and a[j] >= a[j - 1]) {
    		j++;
    	}
    	if (j < n) {
    		ans++;
    	} else {
    		ans = -1;
    	}
    	i = j;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
