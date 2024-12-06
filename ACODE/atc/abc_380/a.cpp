#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][0];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i][1];
    }

    int k;
    std::cin >> k;
    std::sort(a.begin(), a.end(), [&](auto &x, auto &y){
        return x[1] < y[1];
    });
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int s = 0;
        std::multiset<int> st;
        for (int j = i; j < n; ++j) {
            st.insert(a[j][0]);
        }
        for (int j = 0; j < k and st.size(); ++j) {
            auto it = st.rbegin();
            s += *it;
            st.erase(st.find(*it));
        }
        ans = std::max(ans, s * a[i][1]);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();

    return 0;
}