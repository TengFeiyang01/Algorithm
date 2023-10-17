#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	std::vector<int> a(3);
	std::cin >> a[0] >> a[1] >> a[2];
	std::sort(a.begin(), a.end());
	bool ok = true;
	if (a[1] % a[0] == 0 and a[2] % a[0] == 0 and a[1] / a[0] + a[2] / a[0] <= 5) {
		std::cout << "YES\n";
	} else if (a[0] == a[1] and a[1] == a[2]) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
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