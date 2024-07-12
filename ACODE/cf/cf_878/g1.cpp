#include <bits/stdc++.h>

void solve() {
    int x;
    std::cin >> x;
    std::vector<int> a(1001);
    a[1000] = x;
    for (int i = 999; i >= 0; --i) {
    	std::cout << "+ " << 1 << std::endl;
    	std::cin >> a[i];
    }

    std::vector<int> b(1001);
    b[0] = a[0];
    for (int i = 1; i <= 1000; ++i) {
    	std::cout << "+ " << 1000 << std::endl;
    	std::cin >> b[i];
    }

    for (int i = 1; i <= 1000000; ++i)
    	if (b[i / 1000] == a[i % 1000]) {
    		std::cout << "! " << i << std::endl;
    		break;
    	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
