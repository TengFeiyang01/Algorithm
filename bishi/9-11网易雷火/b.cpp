#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;


void solve() {
    std::string s, t;
   	std::cin >> s >> t;
   	if (s == "sort1") {
   		if (t == "asc") {
 	  		std::cout << "dog\nbre\ncat\nace\n";
   		} else {
	   		std::cout << "ace\ncat\nbre\ndog\n";
   		}
   	} else {
   		if (t == "asc") {
   			std::cout << "dog\ncat\nbre\nace\n";
   		} else {
   			std::cout << "ace\nbre\ncat\ndog\n";
   		}
   	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
