#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    int cnt = n * (n - 1) / 2;
    std::map<int, int> a;
    for (int i = 0, x; i < cnt; ++i) {
    	std::cin >> x;
    	a[x]++;
    }
    int t = n - 1;
    for (auto [x, y] : a) {
        while (y) {
            std::cout << x << " ";
            y -= t--;
        }        
    }

    std::cout << 1000000000 << "\n";
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
