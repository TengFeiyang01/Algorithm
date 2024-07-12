#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    int idx = 0;
    for (int i = 0; i < n; ++i) {
   		if (a[i] >= 0) {
    		a[i] = -a[i] - 1;
   		}
   		if (a[i] < a[idx]) {
   			idx = i;
   		}
   	}
   	if (n % 2) {
   		a[idx] = -a[idx] - 1;
   	}
   	for (int i = 0; i < n; ++i) {
   		std::cout << a[i] << " \n"[i == n - 1];
   	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}