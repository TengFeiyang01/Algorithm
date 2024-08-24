#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int Q;
    std::map<int, int> st;
    std::cin >> Q;
    while (Q--) {
    	int op, x;
    	std::cin >> op;
    	if (op == 1) {
    		std::cin >> x;
    		st[x]++;
    	} else if (op == 2) {
    		std::cin >> x;
    		if (--st[x] == 0) {
    			st.erase(x);
    		}
    	} else {
    		std::cout << st.size() << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
