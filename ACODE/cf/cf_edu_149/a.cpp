#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

std::vector<int> primes;
int st[N + 1]{0};


void solve() {
    int n, k;
    std::cin >> n >> k;
    if (n % k == 0) {
        std::cout << 2 << "\n";
    	std::cout << 1 << " " << n - 1 << "\n";
    } else {
    	std::cout << 1 << "\n";
    	std::cout << n << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    for (int i = 2; i <= N; ++i) {
        if (!st[i]) primes.push_back(i);
        for (auto p : primes) {
            if (i * p > N) break;
            st[i * p] = 1;
        }
    }
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
