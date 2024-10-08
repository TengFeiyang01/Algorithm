#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> p[i];
        p[i]--;
    }
    
    int minlose = n;
    int min = n;
    int ans = 0;
    for (int i = 0; i < n; i++)  {
        int win = 0;  //先手必胜
        if (p[i] < min) {
            min = p[i];
            win = 1; 
        } else {
            win = (minlose < p[i]);
        }
        if (!win) {
            ans += 1;
            minlose = std::min(minlose, p[i]);
        }
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
