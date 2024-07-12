#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int k;
    std::string s;
    std::cin >> k >> s;
    i64 ans = 0, n = s.size();
    std::vector<int> a, st;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == '(') {
    		st.push_back(i);
    	} else {
    		a.push_back((i - st.back()) / 2);
    		st.pop_back();
    	}
    }
    std::ranges::sort(a);
    for (int i = 0; i < int(a.size()) - k; ++i) {
    	ans += a[i];
    }
    std::cout << ans << "\n";
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
