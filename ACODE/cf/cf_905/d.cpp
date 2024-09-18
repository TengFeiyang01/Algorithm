#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(n);
    a[0] = 1;
    for (int i = 1; i < n; ++i) {
    	std::cin >> a[i];
    }

    for (int j = 0; j < n; ++j) {
    	std::cin >> b[j];
    }

  	std::ranges::sort(a);
  	std::ranges::sort(b);
  	
    int ans = 0;
    for (int i = 0, j = 0; i < n && j < n; ++i) {
        while (j < n && a[i] >= b[j]) {
            j++;
        }
        if (j < n) {
            ans++;
        }
        if (++j == n) {
            break;
        }
    }

    std::cout << n - ans << "\n";
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