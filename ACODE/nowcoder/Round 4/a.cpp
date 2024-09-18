#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    std::cin >> n >> k;
    if (k * 3 > n) {
    	std::cout << "-1\n";
    } else {
    	for (int i = 0; i < k; ++i) {
    		std::cout << "you";
    	}
    	for (int i = k * 3; i < n; ++i) {
    		std::cout << "y";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
