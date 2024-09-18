#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::vector<std::string> s(3);
    for (int i = 0; i < 3; ++i) {
    	std::string t;
    	std::cin >> t;
    	for (auto c : t) {
    		if (isalpha(c)) {
    			s[i] += tolower(c);
    		}
    	}
    }
    std::set<std::string> st;
    st.insert(s[0] + s[1] + s[2]);
    st.insert(s[0] + s[2] + s[1]);
    st.insert(s[1] + s[2] + s[0]);
    st.insert(s[1] + s[0] + s[2]);
    st.insert(s[2] + s[0] + s[1]);
    st.insert(s[2] + s[1] + s[0]);  

    int n;
    std::cin >> n;
    auto f = [&]() {    
        std::string a, t;
        std::cin >> a;
        for (auto c : a) {
        	if (isalpha(c)) 
        		t += tolower(c);
        }
        return t;
    };
    for (int i = 0; i < n; ++i) {
        auto t = f();
        if (st.count(t)) {
            std::cout << "ACC\n";
        } else {
            std::cout << "WA\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
