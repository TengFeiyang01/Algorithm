#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, k;
    std::map<int, int> cnt;
    std::cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }

    int now = 0;
    for (int i = 100000; i >= 1; --i) {
        now += cnt[i];
        if (now == k) {
            std::cout << "YES\n";
            return;
        } 
    }
    
    std::cout << "NO\n";
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
