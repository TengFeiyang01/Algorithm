#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
   	std::vector<std::array<int, 2>> a(n);
   	for (int i = 0; i < n; ++i) {
   		std::cin >> a[i][0] >> a[i][1];
   	}
   	std::ranges::sort(a);
   	int q;
   	std::vector<int> pre(n);
   	pre[0] = a[0][1];
   	for (int i = 1; i < n; ++i) {
   		pre[i] = std::max(pre[i - 1], a[i][1]);
   	}

   	std::cin >> q;
   	while (q--) {
   		int x;
   		std::cin >> x;
   		int l = std::ranges::upper_bound(a, std::array<int, 2>{x, inf}) - a.begin() - 1;
   		if (a[0][0] > x) {
   			std::cout << "-1\n";
   		} else {
   			std::cout << pre[l] << "\n";
   		}
   	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
