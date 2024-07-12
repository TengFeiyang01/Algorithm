#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::string s;
    std::string t = "aeiou";
    std::cin >> s;
    for (auto c : s) {
    	if (t.find(c) == -1) {
    		std::cout << c;
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
