#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    int a = 1, b = n;
    while (a < b) {
    	std::cout << a++ << " ";
    	std::cout << b-- << " ";
    }
    if (a == b) {
        std::cout << a << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
