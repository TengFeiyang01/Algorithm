#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    i64 ans = 0;
    std::vector<std::array<int, 2>> a(n);
    for (auto &[x, y] : a) {
    	std::cin >> x >> y;
    }
    std::ranges::sort(a, [&](auto &x, auto &y){
    	return x[1] > y[1];
    });
    i64 s = 0;
    std::multiset<int> st;
    for (int i = 0; i < n; ++i) {
    	st.insert(a[i][0]);
    	s += a[i][0];
    	if (st.size() > m) {
    		s -= *st.begin();
    		st.erase(st.begin());
    	}
    	ans = std::max(ans, s * a[i][1]);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
