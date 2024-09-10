#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::set<int> st;
    std::map<int, int> cnt;
    for (int i = 0; i <= n; ++i) {
    	st.insert(i);
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	if (st.count(a[i])) {
    		st.erase(a[i]);
    	}
	   	cnt[a[i]]++;
    }

   	int p = *st.begin();
   	int ok = 0;
    if (k == p or (k < p and cnt[k] == 1)) {
    	ok = 1;
    } else {
    	if (k == p + 1 and cnt[p + 1] == 1) {
    		ok = 1;
    	}
    	if (cnt[p - 1] > 1) {
    		st.erase(p);
    		p = *st.begin();
    		if (p == k) {
    			ok = 1;
    		} 
    	} else if (cnt[p + 1] > 1) {
    		st.erase(p);
    		p = *st.begin();
    		if (p == k) {
    			ok = 1;
    		}
    	}
    }
    std::cout << (ok ? "YES" : "NO") << "\n";
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
