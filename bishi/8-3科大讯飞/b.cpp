#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    while (n--) {
    	std::string s;
    	std::cin >> s;
    	int x = std::stoi(s.substr(0, 2));
    	x = (x + 16) % 24;
    	if (x < 10) {
    		std::cout << "0" << std::to_string(x) << s.substr(2) << "\n";
    	} else {
    		std::cout << std::to_string(x) << s.substr(2) << "\n";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
