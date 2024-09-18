#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::map<std::string, std::string> mp;
    for (int i = 0; i < n; ++i) {
    	std::string s;
    	std::cin >> s;
    	int f = 0, g = 0, t = 0;;
    	if (isdigit(s[0])) {
    		f = 1;
    	}
    	for (int j = 1; j < s.size(); ++j) {
    		if (isdigit(s[j])) {
    			g++;
    		}
    		if (isalpha(s[j])) {
    			t++;
    		}
    	}
    	int m = s.size();
    	if (!f and g == m - 1) {
    		std::cout << "standard" << "\n";
    		continue;
    	}
    	if (!f and g + t == m - 1) {
    		std::cout << "mix" << "\n";
    		continue;
    	}
    	if (f and t == m - 1) {
    		std::cout << "special" << "\n";
    		continue;
    	}
    	std::cout << "invalid\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
