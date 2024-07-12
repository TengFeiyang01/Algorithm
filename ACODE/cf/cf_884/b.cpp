#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    if (n == 1) {
    	std::cout << 1 << "\n";
    } else if (n == 2) {
    	std::cout << "2 1\n";
    } else {
    	std::vector<int> a(n);
    	// a[0] = 2;
    	// a[n / 2] = 1;
    	// a[n / 2 + 1] = 3;
    	// int num = 4;
    	// int l = 0, r = n - 1;
    	// while (l < r) {
    	// 	while (a[l] != 0 and l < r) {
    	// 		l += 1;
    	// 	}
    	// 	if (l < r) a[l] = num++;
    	// 	while (a[r] != 0 and l < r) {
    	// 		r -= 1;
    	// 	}
    	// 	if (l < r) a[r] = num++;
    	// }
        a[0] = 2;
        a[n / 2] = 1;
        a[n - 1] = 3;
        for (int i = 0, num = 4; i < n; ++i) {
            if (!a[i]) a[i] = num++;
        }

    	for (int i = 0; i < n; ++i) {
    		std::cout << a[i] << " \n"[i == n - 1];
    	}
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
