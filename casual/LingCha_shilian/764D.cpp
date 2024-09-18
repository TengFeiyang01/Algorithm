#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k, a, b;
    char cg = 'G', cb = 'B';
    std::cin >> n >> k >> a >> b;
    if (a < b) {
    	std::swap(a, b);
    	std::swap(cb, cg);
    }
    b++;
    if ((a - 1) / b >= k) {
		std::cout << "NO\n";
    } else {
    	std::string base = cb + std::string(a / b, cg);
        std::cout << base.substr(1);
    	for (int i = 0; i < b - a % b - 1; ++i) {
    	   std::cout << base;
        }  
        for (int i = 0; i < a % b; ++i) {
            std::cout << base + cg;
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
	