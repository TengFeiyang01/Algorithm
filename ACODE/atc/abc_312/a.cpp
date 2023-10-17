#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::set<std::string> st;
    std::string s;
    std::cin >> s;
    st.insert("ACE");
    st.insert("BDF");
    st.insert("CEG");
    st.insert("DFA");
    st.insert("EGB");
    st.insert("FAC");
    st.insert("GBD");
    if (st.count(s)) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
