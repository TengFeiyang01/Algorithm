#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    int ans = INT_MAX;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::multiset<int> st;
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    	st.insert(b[i]);
    	ans = std::min(ans, a[i] + b[i]);
    }
    for (int i = 0; i < n; ++i) {
    	st.erase(st.find(b[i]));
    	ans = std::min(ans, std::max(*st.begin(), a[i]));
    }
    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
