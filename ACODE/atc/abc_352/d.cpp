#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> p(n);
    std::set<int> st;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	p[--x] = i;
    }
    int ans = inf;
    for (int i = 0; i < n; ++i) {
    	st.insert(p[i]);
    	if (i >= k - 1) {
    		ans = std::min(ans, *st.rbegin() - *st.begin());
    		st.erase(p[i - k + 1]);
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
