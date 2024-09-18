#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;


void solve() {
    int n, k;
    i64 m, ans = 0;
    std::cin >> n >> k >> m;
    std::vector<int> a(n);
    std::multiset<int> st;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        ans += a[i] / k;
        if (a[i] % k) {
            st.insert(a[i] % k);
        }
    }
    while (!st.empty()) {
        int need = k - *st.rbegin();
        if (m >= need) {
            m -= need;
            ans++;
            st.erase(st.find(need));
        } else {
            break;
        }
    }
    if (m) {
        ans += m / k;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
