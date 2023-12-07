#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> primes;
    std::vector<bool> st(n + 1);

    for (int i = 2; i <= n; ++i) {
    	if (!st[i]) {
    		primes.push_back(i);
    	}
    	for (auto p : primes) {
    		if (i * p > n) break;
    		st[i * p] = true;
    		if (i % p == 0) break;
    	}
    }
    std::cout << primes.size() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
