#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    bool ok = true;
    std::string a, b;
    for (int i = 0; i < n; ++i) {
        a += "()";
        b += '(';
    }
    b += std::string(n, ')');
    if (a.find(s) == -1) {
        std::cout << "YES\n" << a << "\n";
    } else if (b.find(s) == -1) {
        std::cout << "YES\n" << b << "\n";
    } else {
        std::cout << "NO\n";
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
