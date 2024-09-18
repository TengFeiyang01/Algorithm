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

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> cnt(k);
    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        cnt[i % k] += (x % k == i % k);
    }
    std::vector<int> need(k, n / k);
    for (int i = 0; i < n % k; ++i) {
        need[i % k] += 1;
    }
    int sw = 0;
    for (int i = 0; i < k; ++i) {
        if (cnt[i] != need[i]) {
            sw += need[i] - cnt[i];
        }
    }
    if (sw == 0) {
        std::cout << "0\n";
    } else if (sw == 2) {
        std::cout << "1\n";
    } else {
        std::cout << "-1\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
