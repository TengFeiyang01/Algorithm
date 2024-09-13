#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> l(m + 1, n), r(m + 1, 0);
    std::set<int> st;
    for (int i = 0, x; i < n; ++i) {
        std::cin >> x;
        l[x] = std::min(l[x], i + 1);
        r[x] = std::max(r[x], i + 1);
    }
    for (int i = 1; i <= m; ++i) {
        st.insert(i);
    }
    for (int i = m - 1; i >= 1; --i) {
        if (!st.count(i)) {
            l[i] = r[i + 1];
            r[i] = r[i + 1];
        }
    }
    for (int i = 1; i <= m; ++i) {
        std::cout << l[i] << " " << r[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
