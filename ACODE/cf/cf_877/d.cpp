#include <bits/stdc++.h>

constexpr int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 1e5 + 13;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::string s;
    std::cin >> s;


    //下标奇偶性
    std::set<int> st;
    for (int i = 0; i < n; ++i) {
    	if (s[i] != "()"[i % 2]) {
    		st.insert(i);
    	}
    }

    int p;
    for (int i = 0; i < q; ++i) {
    	std::cin >> p;
    	s[--p] ^= 1;
    	if (s[p] != "()"[p % 2]) {
    		st.insert(p);
    	} else {
    		st.erase(p);
    	}
    	//1: (  0: )  不匹配的左括号在右括号右边 ： 连续两个左括号在左边
    	(n % 2 ? std::cout << "NO\n" : std::cout << (st.empty() ? "YES\n" : (*st.begin() % 2 > *st.rbegin() % 2 ? "YES\n" : "NO\n")));
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

	solve();

    return 0;
}
