#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) {
    	if (i + 2 < s.size() and s.substr(i, 3) == "red") {
    		cnt++;
    	}
    }
    std::cout << (cnt >= 2 ? "Yes\n" : "No\n");
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
