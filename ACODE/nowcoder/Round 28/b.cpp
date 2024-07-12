#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	std::multiset<std::string> st;
	std::string s;
	std::cin >> s;
	for (int i = 0; i < s.size() - 1; ++i) {
		st.insert(s.substr(i, 2));
	}
	for (auto x : st) {
		std::cout << x << "\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
