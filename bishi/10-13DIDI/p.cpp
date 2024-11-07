#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m, -1);
    std::set<int> st;
    for (int i = 0; i < m; ++i) {
    	st.insert(i);
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	int x = a[i] % m;
    	if (st.size() == 0) continue;
    	auto it = st.lower_bound(x);
    	if (it == st.end()) it = st.begin();
    	b[*it] = a[i];
    	st.erase(it);
    }
    for (int i = 0; i < m; ++i) {
    	std::cout << b[i] << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
