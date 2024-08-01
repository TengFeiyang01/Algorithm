#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
 	int a, b, c;
 	std::cin >> a >> b >> c;
 	std::string color;
 	std::cin >> color;
 
 	if (color == "Red") {
 		std::cout << std::min(b, c);
 	} else if (color == "Green") {
 		std::cout << std::min(a, c);
 	} else {
 		std::cout << std::min(a, b);
 	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
