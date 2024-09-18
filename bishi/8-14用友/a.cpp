#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int t, s;
    std::cin >> t >> s;
    std::priority_queue<int> pq;
    int ans = 0, f = 1;
    int d, v;
    char op;
    std::vector<std::array<int, 2>> a;
    while (std::cin >> d >> op >> v) {
        a.push_back({d, v});
    }
    a.push_back({t, 0});
    std::ranges::sort(a);
    for (auto [d, v] : a) {
        if (s < d) {
            while (s < d and !pq.empty()) {
                ans++;
                s += pq.top();
                pq.pop();
            } 
            if (s < d) {
                std::cout << "-1\n";
                return;
            }
        } else {
            pq.push(v);
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
