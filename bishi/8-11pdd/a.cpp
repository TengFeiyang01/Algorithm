#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 3>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    i64 ans = 0;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
    	int p = a[i][0], x = a[i][1], d = a[i][2];
    	if (ans <= x) {
    		ans = x;
    	} else {
    		ans = x + (ans - x + d - 1) / d * d;
    	}
    	ans++;
    }
    std::cout << --ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
