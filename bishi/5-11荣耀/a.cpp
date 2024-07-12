#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::vector<std::string> good, bad;
    std::set<std::string> st;
    while (std::getline(std::cin, s)) {
    	if (s.empty()) {
    		break;
    	}
    	bool ok = true;
    	for (auto c : s) {
    		if (!isalnum(c)) {
    			ok = false;
    		}
    	}


    	if (!ok) {
    		bad.push_back(s);
    	} else {
    		if (!st.count(s)) {
    			good.push_back(s);
		    	st.insert(s);
    		}
    	}
    }
    int n = good.size();
    for (int i = 0; i < n; ++i) {
    	std::cout << good[i] << " \n"[i == n - 1];
    }
    n = bad.size();
    for (int i = 0; i < n; ++i) {
    	std::cout << bad[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
