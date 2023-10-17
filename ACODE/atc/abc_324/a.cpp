#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::set<int> st;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	st.insert(x);
    }
    if (st.size() > 1) {
    	std::cout << "No\n";
    } else {
    	std::cout << "Yes\n";
    }
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}