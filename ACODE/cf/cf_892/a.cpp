#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::vector<int> b, c;
    std::sort(a.begin(), a.end());
    if (a[0] == a[n - 1]) {
        std::cout << "-1\n";
    } else {
        int i = 0;
        for (; i < n and a[i] == a[0]; i++) {
            b.push_back(a[i]);
        }
        for (; i < n; ++i) {
            c.push_back(a[i]);
        }
        std::cout << b.size() << " " << c.size() << "\n";
        for (int i = 0; i < b.size(); ++i) {
            std::cout << b[i] << " \n"[i == b.size() - 1];
        }
        for (int i = 0; i < c.size(); ++i) {
            std::cout << c[i] << " \n"[i == c.size() - 1];
        }
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
