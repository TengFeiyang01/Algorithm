#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, c, d;
    std::cin >> n >> c >> d;
    std::vector<int> a(n * n);
    for (int i = 0; i < n * n; ++i) {
        std::cin >> a[i];
    }
    int x = std::ranges::min(a);
    std::multiset<int> st;
    for (int i = 0; i < n; ++i) {
        i64 t = x + i * d;
        for (int j = 0; j < n; ++j) {
            st.insert(t + j * c);
        }
    }

    std::multiset<int> b{a.begin(), a.end()};
    if (st == b) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
