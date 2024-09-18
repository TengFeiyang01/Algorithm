#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::set<std::string> st;
    for (int i = 0; i < n; ++i) {
    	std::string s;
    	std::cin >> s;
    	auto t = s;
    	std::reverse(t.begin(), t.end());
    	if (!st.count(s) and !st.count(t)) {
    		st.insert(s);
    	} 
    }
    std::cout << st.size() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
