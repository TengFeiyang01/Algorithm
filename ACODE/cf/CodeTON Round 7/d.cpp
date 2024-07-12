#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    std::set<int> st;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (a[i] == 1) st.insert(i);
    }
    int mx = -1, mn = n;
    while (q--) {
    	int op; std::cin >> op;
    	if (op == 1) {
    		int sum;
    		std::cin >> sum;
    		if (!st.empty()) {
    			int len = st.size();
    			mx = *st.rbegin(), mn = *st.begin();
    			int t = (mx - mn + 1) * 2 - len;
    			if (sum <= t) {
    				std::cout << "YES\n";
    			} else {
    				int more = std::max(n - mx - 1, mn);
    				if ((sum - t) % 2) {
    					// 奇偶性不同  只能用一侧的2
    					if ((sum - t + 1) / 2 <= more) {
    						std::cout << "YES\n";
    					} else {
    						std::cout << "NO\n";
    					}
    				} else {
    					more = n - mx - 1 + mn;
    					if ((sum - t) / 2 <= more) {
    						std::cout << "YES\n";
    					} else {
    						std::cout << "NO\n";
    					}
    				}
    			}
    		} else {
    			if (sum % 2) {
    				std::cout << "NO\n";
    			} else {
    				std::cout << "YES\n";
    			}
    		}
    	} else {
    		int i, v;
    		std::cin >> i >> v;
    		--i;
    		if (a[i] == 1 and v == 2) {
    			st.erase(i);
    		} 
    		if (a[i] == 2 and v == 1) {
    			st.insert(i);
    		}
    		a[i] = v;
    	}
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
