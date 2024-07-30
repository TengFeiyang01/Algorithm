#include <bits/stdc++.h>
using i64 = long long;


void solve() { 
    int n;
    std::cin >> n;
    bool ok = true;
    char last = ' ';
    while (n--) {
        std::string s;
        std::cin >> s;
        if (s[1] == 'w' and last == 'w' and n) {
            ok = false;
        }
        last = s[1];
    }
    if (ok) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    std::ios::sync_with_stdio(0),std::cin.tie(0);
    
    solve();
    return 0;
}