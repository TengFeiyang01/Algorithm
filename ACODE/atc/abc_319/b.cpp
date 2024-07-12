#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::cout << 1;
	std::vector<int> d;
	for (int i = 1; i <= n; ++i) {
		int ok = 0;
		for (int j = 1; j <= 9; ++j) {
			if (n % j == 0 and i % (n / j) == 0) {
				std::cout << j;
				ok = 1;
				break;
			}
		}
		if (!ok) std::cout << "-";
	}  
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}