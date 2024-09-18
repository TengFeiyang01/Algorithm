#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

struct movie {
	int id;
	std::string dir, act, type;
}a[2000];

void solve() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i].id >> a[i].dir >> a[i].act >> a[i].type;
    }
    std::string t, op;
    std::cin >> op >> t;
    std::set<int> st;
    for (int i = 0; i < n; ++i) {
    	if (op == "T") {
    		if (a[i].type == t) {
    			st.insert(a[i].id);
    		}
    	} else if (op == "D") {
    		if (a[i].dir == t) {
    			st.insert(a[i].id);
    		}
    	} else if (op == "A") {
    		if (a[i].act == t) {
    			st.insert(a[i].id);
    		}
    	}
    }
    if (st.empty()) {
    	std::cout << "-1\n";
    } else {
    	std::vector<int> ans;
    	for (int x : st) {
    		ans.push_back(x);
    	}
    	for (int i = 0; i < ans.size(); ++i) {
    		std::cout << ans[i] << " \n"[i == ans.size() - 1];
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
