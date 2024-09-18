#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n;
    std::vector<int> a(n);
    std::multiset<int> st;
    for (int &x : a) {
    	std::cin >> x;
    }
    std::cin >> m;
    std::vector<int> b(m);
    for (int &x : b) {
    	std::cin >> x;
    	st.insert(x);
    }

    std::sort(b.begin(), b.end());
    std::sort(a.begin(), a.end());
    int need = n / 2 + 1;
    i64 ans = 0, cnt = 0;
    for (int i = need - 1; i >= 0; --i) {
    	int x = a[i];
    	auto it = st.upper_bound(x);
    	if (it == st.end()) {
    		ans += x + 1;
    		cnt++;
    	} else {
    		st.erase(it);
    	}
    }
    if (cnt > n - m) {
    	ans = -1;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
