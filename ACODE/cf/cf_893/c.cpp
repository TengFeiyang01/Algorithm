#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;

    std::vector<int> a;
    a.reserve(n);
    for (int i = 1; i <= n; i += 2) {
        for (int j = i; j <= n; j *= 2) {
            a.push_back(j);
        }
    }

    //1 2 4 
    //3 6 12 
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
