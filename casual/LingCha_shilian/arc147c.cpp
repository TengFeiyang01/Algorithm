#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    i64 ans = 0;
   	std::vector<int> l(n), r(n);
   	for (int i = 0; i < n; ++i) {
   		std::cin >> l[i] >> r[i];
   	}
   	std::ranges::sort(l, std::greater());
   	std::ranges::sort(r);

    //l尽可能的大 r尽可能小
	for (int i = 0; l[i] > r[i]; i++) {
		ans += (n - 1 - i * 2LL) * (l[i] - r[i]);
	}   	
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}