#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    std::map<std::string, int> mp{
    	{"AC", 2},
    	{"AD", 2},
    	{"EC", 2},
    	{"EB", 2},
    	{"DB", 2},
    	{"DA", 2},
    };
   	int len = 0, len2 = 0;
   	if (mp.count(s)) {
   		len = mp[s];
   	} else {
   		std::ranges::reverse(s);
   		len = mp[s];
   	}
   	if (mp.count(t)) {
   		len2 = mp[t];
   	} else {
   		std::ranges::reverse(t);
   		len2 = mp[t];
   	}
   	std::cout << ((len == len2) ? "Yes\n" : "No\n");
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
