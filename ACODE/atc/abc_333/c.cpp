#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::vector<i64> a{1, 11, 111, 1111, 11111, 111111LL, 1111111LL, 11111111LL, 111111111LL, 1111111111LL, 11111111111LL, 111111111111LL, 1111111111111LL};
    std::set<i64> st;
    for (auto x : a) {
    	for (auto y : a) {
    		for (auto z : a) {
    			st.insert(x + y + z);
    		}
    	}
    }
    int n;
    std::cin >> n;
    std::vector<i64> b{st.begin(), st.end()};
    std::cout << b[n - 1] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
