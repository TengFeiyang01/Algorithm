#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, need;
    std::cin >> n >> need;
    std::vector<std::vector<std::string>> a(n);
    for (int i = 0; i < n; ++i) {
    	int m;
    	std::cin >> m;
    	for (int j = 0; j < m; ++j) {
    		std::string y; std::cin >> y;
    		a[i].push_back(y);
    	}
    }
    int p = -1, q = -1;
    for (int i = 0; i < n; ++i) {
    	for (int j = i + 1; j < n; ++j) {
    		std::set<std::string> st;
    		for (auto x : a[i]) st.insert(x);
    		for (auto x : a[j]) st.insert(x);
    		if (st.size() == need) {
    			std::cout << "YES\n";
    			std::cout << i + 1 << " " << j + 1 << "\n";
    			return;
    		}
    	}
    }
    std::cout << "NO\n";
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
