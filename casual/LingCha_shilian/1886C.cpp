#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	i64 k, n;
	std::string s;
	std::cin >> s >> k;
	n = s.size();
	int cnt = 0;
	while (k > n - cnt) {
		k -= n - cnt;
		cnt++;
	}

	std::string stk;
	int i = 0;
	while (i < n) {
		while (cnt > 0 and !stk.empty() and stk.back() > s[i]) {
			stk.pop_back();
			cnt--;
		}
		stk.push_back(s[i++]);
	}
	std::cout << stk[k - 1];
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
