#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), ans(n), id(n);
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        pq.push(a[i]);
        id[i] = i;
    }
    std::ranges::sort(id, [&](int i, int j){
        return a[i] < a[j];
    });

    i64 sum = a[id[0]], j = 1;
    for (int i = 0; i < n; ++i) {
        if (j <= i) sum += a[id[j]], j = i + 1;
        while (j < n and sum >= a[id[j]]) {
            sum += a[id[j]];
            ++j;
        }
        // std::cout << a[id[i]] << " " << sum  << " " << j << "\n";
        ans[id[i]] = j - 1;
    }
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
