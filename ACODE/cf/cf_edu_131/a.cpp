#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    std::set<int> st;
    for (auto c : s) st.insert(c);
    for (auto c : t) st.insert(c);
    	std::cout << st.size() - 1 << "\n";
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
