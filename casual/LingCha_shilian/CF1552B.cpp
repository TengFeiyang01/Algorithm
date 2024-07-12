#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 5>> a(n);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < 5; ++j) {
    		std::cin >> a[i][j];
    	}
    }
    int x = 0;
    for (int i = 1; i < n; ++i) {
        int f = 0;
        for (int j = 0; j < 5; ++j) {
            if (a[i][j] < a[x][j]) {
                f++;
            }
        }
        if (f >= 3) x = i;
    }   
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int f = 0;
        for (int j = 0; j < 5; ++j) {
            if (a[x][j] < a[i][j]) {
                f++;
            }
        }
        if (f >= 3) {
            cnt++;
        }
    }
    if (cnt != n - 1) {
        std::cout << "-1\n";
    } else {
        std::cout << x + 1 << "\n";
    }
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
