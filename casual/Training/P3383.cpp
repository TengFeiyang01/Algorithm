#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> primes, st(n + 1);
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
    for (int i = 0; i < m; ++i) {
    	int x;
    	std::cin >> x;
    	std::cout << primes[x - 1] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
