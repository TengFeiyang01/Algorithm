#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	std::string s;
   	std::cin >> s;
    if (s == "abc") {
        std::cout << "YES\n";
        return;
    }
   	for (int i = 0; i < 3; ++i) {
   		for (int j = i + 1; j < 3; ++j) {
   			std::swap(s[i], s[j]);
   			if (s == "abc") {
   				std::cout << "YES\n";
   				return;
   			}
   			std::swap(s[i], s[j]);
   		}
   	}
   	std::cout << "NO\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}