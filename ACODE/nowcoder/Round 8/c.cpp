#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    int a = n, b = 1;
    while (a > b) {
    	std::cout << b << " " << a << " ";
		a--;
		b++;    	
    }
    if (a == b) {
    	std::cout << a << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
