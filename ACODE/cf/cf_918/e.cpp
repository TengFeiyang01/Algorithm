#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1), s(n + 1), odd(n + 1);
    std::set<i64> st;

    bool ok = false;
    st.insert(0);
    for (int i = 1; i <= n; ++i) {	
    	std::cin >> a[i];
    	s[i] = s[i - 1] + a[i];
    	odd[i] = odd[i - 1] + (i & 1) * a[i];
    	if (st.count(s[i] - 2LL * odd[i])) {
    		ok = true;
    	}
    	st.insert(s[i] - 2LL * odd[i]);
    }
    // s[r] - s[l] == 2*(odd[r]-odd[l])
    // s[r] - 2*odd[r] == s[l]-2*odd[l];
    if (ok) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
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
