#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;
	int ans = 0;
	s = " " + s;

	std::set<int> pre_one, suf_zero;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == '1') {
			pre_one.insert(i);
		} else {
			suf_zero.insert(-i);
		}
	}
	pre_one.insert(n + 1);
	suf_zero.insert(0);

	std::set<PII> st;
	while (m--) {
		int l, r;
		std::cin >> l >> r;
		int t1 = *pre_one.lower_bound(l);
		int t2 = -(*suf_zero.lower_bound(-r));
		if (t1 > t2) st.insert({0, 0});
		else st.insert({t1, t2});
	}
	std::cout << st.size() << "\n";
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
