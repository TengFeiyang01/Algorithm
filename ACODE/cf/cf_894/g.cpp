#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::multiset<int> s, d{0};
    
    auto add = [&](int x) {
        auto it = s.insert(x);
        auto r = std::next(it);
        if (it != s.begin()) {
            d.insert(x - *std::prev(it));
        }
        if (r != s.end()) {
            d.insert(*r - x);
        }
        if (it != s.begin() && r != s.end()) {
            d.extract(*r - *std::prev(it));
        }
    };
    
    auto del = [&](int x) {
        auto it = s.find(x);
        auto r = std::next(it);
        if (it != s.begin()) {
            d.extract(x - *std::prev(it));
        }
        if (r != s.end()) {
            d.extract(*r - x);
        }
        if (it != s.begin() && r != s.end()) {
            d.insert(*r - *std::prev(it));
        }
        s.erase(it);
    };
    
    for (int i = 0; i < n; i++) {
        add(a[i]);
    }
    
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        del(a[x]);
        a[x] = y;
        add(a[x]);
        int ans = *s.rbegin() + *d.rbegin();
        std::cout << ans << " \n"[i == q - 1];
    }
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
