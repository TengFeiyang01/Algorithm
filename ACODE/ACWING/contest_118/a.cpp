#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, a;
    std::cin >> n >> a;
    std::string s;
    for (char c = 'a'; c <= 'z'; ++c) s += c;
    for (int i = 0; i < n; ++i) {
    	std::cout << s[i % a];
    }
    std::cout << "\n";
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