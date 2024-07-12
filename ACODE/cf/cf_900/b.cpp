#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a{1, 6};
    for (int i = 2; i < n; ++i) {
        a.push_back(a[i - 2] + 9);
    }
    for (int i = 0; i < n; ++i) {
    	std::cout << a[i] << " \n"[i == n - 1];
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