#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	int n;
    std::string s;
    std::cin >> n >> s;
 	std::vector<int> l(n), ans(n);
 	for (int i = 0; i < n; ++i) {
        if (i) l[i] += l[i - 1];
 		if (s[i] == '(') {
 			l[i]++;
 		} else {
 			l[i]--;
 		}
 	}
    if (l.back() != 0) {
        std::cout << "-1\n";
        return;
    }
 	std::set<int> st;
 	for (int i = 0; i < n; ++i) {
 		if (l[i] > 0) {
 			ans[i] = 1;
 		} else if (l[i] < 0) {
 			ans[i] = 2;
 		} else if (l[i] == 0) {
 			ans[i] = ans[i - 1];
 		}
 		st.insert(ans[i]);
 	}
 	std::cout << st.size() << "\n";
 	if (st.size() == 1) {
        ans.assign(n, 1);
    }
    for (int i = 0; i < n; ++i) {
 		std::cout << ans[i] << " \n"[i == n - 1];
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
