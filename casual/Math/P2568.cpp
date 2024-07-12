#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
const int N = 1e7 + 1;

void solve() {
    int n;
    std::cin >> n;
    std::bitset<N> st;
    std::vector<i64> prime, phi(n + 1), sum(n + 1);
    i64 ans = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
    	if (!st[i]) {
    		prime.push_back(i);
            phi[i] = i - 1;
    	}
    	for (auto p : prime) {
    		if (i * p > n) break;
    		st[i * p] = 1;
    		if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            } else {
                phi[i * p] = phi[i] * phi[p];
            }
    	}
    }
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + phi[i];
    }

    for (auto p : prime) {
        ans += 2LL * sum[n / p] - 1;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
