#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k, x;
    std::cin >> n >> k >> x;
    std::vector<int> a(n);

    std::multiset<int> st;
    for (int i = 0; i <= n; ++i) {
    	st.insert(i);
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }

    i64 ans = i64(n) * x;
    for (int i = n - 1; i >= 0; --i) {
    	if (st.count(a[i])) {
    		st.erase(st.find(a[i]));
    	}
    	ans = std::min(ans, i64(k) * (*st.begin()) + i64(i) * x);
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
