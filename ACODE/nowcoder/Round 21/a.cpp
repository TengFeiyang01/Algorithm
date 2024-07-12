#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::string t, s = "Baidu";
    std::cin >> t;
    std::sort(t.begin(), t.end());
    std::sort(s.begin(), s.end());
    if (s == t) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }
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
