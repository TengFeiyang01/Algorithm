#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;


void solve() {
    std::string s;
    int n;
    std::cin >> n >> s;
    if (s.find("ab") != -1 or s.find("ba") != -1) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    solve();

    return 0;
}
