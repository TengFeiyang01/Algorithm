#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;


std::vector<int> minp, primes;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}
		
void solve() {
	int n;
	std::cin >> n;
	for (int p : primes) {
		if (n % p == 0) {
			std::cout << p << "\n";
			return;
		}
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    sieve(int(2e5+1));
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
