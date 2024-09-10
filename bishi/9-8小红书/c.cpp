#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    std::map<int, std::set<int>> pos;
    
    std::multiset<int> st;

    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	pos[a[i]].insert(i);
    }
    for (auto [k , v] : pos) {
    	st.insert(*v.rbegin() - *v.begin());
    }

    for (int i = 0; i < q; ++i) {
    	int op, p, x;
    	std::cin >> op;
    	if (op == 2) {
    		std::cout << *st.rbegin() << "\n";
    	} else {
    		std::cin >> p >> x;
    		--p;

    		auto &v = pos[a[p]];
    		st.erase(st.find(*v.rbegin() - *v.begin()));
    		v.erase(p);
    		if (v.size()) {
    			st.insert(*v.rbegin() - *v.begin());
    		}
    		
    		if (!pos.count(x)) {
    			pos[x] = std::set<int>{};
    		} 
    		
    		auto &v1 = pos[x];
    		if (v1.size()) {
	    		st.erase(st.find(*v1.rbegin() - *v1.begin()));
    		}
    		v1.insert(p);
    		st.insert(*v1.rbegin() - *v1.begin());
    		
    		a[p] = x;
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
