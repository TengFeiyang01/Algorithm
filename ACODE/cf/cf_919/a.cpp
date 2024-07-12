#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, op, x;
    int mx = inf, mn = 0;
    std::cin >> n;
    std::set<int> st; 
    while (n--) {
        std::cin >> op >> x;
        if (op == 1) {
            mn = std::max(mn, x);
        } else if (op == 2) {
            mx = std::min(mx, x);
        } else {
            st.insert(x);
        }
        while (st.size() and *st.begin() < mn) {
            st.erase(st.begin());
        }
        while (st.size() and *st.rbegin() > mx) {
            st.erase(st.find(*st.rbegin()));
        }
    }
    int ans = 0;
    if (mx >= mn) {
        ans += mx - mn + 1;
        ans -= int(st.size());
    }
    std::cout << ans << "\n";
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
