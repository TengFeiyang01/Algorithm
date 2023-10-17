#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	std::vector<int> a(3);
	for (int &x : a) std::cin >> x;
	std::sort(a.begin(), a.end());
	if (a[2] + a[1] >= 10) {
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
