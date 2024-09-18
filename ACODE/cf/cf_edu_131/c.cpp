#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    std::multiset<int> st;
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
        st.insert(b[i]);
        cnt[b[i]]++;
    }
    for (int i = 0; i < n; ++i) {
    	std::cout << *std::lower_bound(b.begin(), b.end(), a[i]) - a[i] << " \n"[i == n - 1];
    }
    std::vector<int> ans(n);

    for (int i = n - 1; i >= 0; --i) {
        // ans[i] = *st.rbegin() - a[i];
        // st.erase(st.lower_bound(a[i]));
        ans[i] = (*cnt.rbegin()).first - a[i];
        auto it = cnt.lower_bound(a[i]);
        if (--cnt[(*it).first] == 0) {
            cnt.erase((*it).first);
        }
    }
    for (int i = 0; i < n; ++i) {
    	std::cout << ans[i] << " \n"[i == n - 1];
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
