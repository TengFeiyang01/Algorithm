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
const int N = 3e6 + 13;

int primes[N], cnt = 0;
bool st[N];

void init() {
    for (int i = 2; i < N; ++i) {
        if (!st[i]) {
            primes[cnt++] = i;
        }
        for (int j = 0; primes[j] * i < N; ++j) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        ll x = 0;
        std::cin >> x;

        for (int i = 0; i < cnt; ++i) {
            if (x % primes[i] == 0 and !st[x / primes[i]]) {
                std::cout << "YES\n";
                continue;
            } else {
                std::cout << "NO\n";
                continue;
            }
        }
    
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    init();
    solve();

    return 0;
}
