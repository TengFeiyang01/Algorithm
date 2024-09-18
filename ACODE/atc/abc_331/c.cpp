#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> cnt;
    std::map<int, std::vector<int>> pos;
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        cnt[-x]++;
        pos[-x].push_back(i);
    }
    i64 tot = 0;
    std::vector<i64> ans(n);
    for (auto [k, v] : cnt) {
        for (auto x : pos[k]) {
            ans[x] = tot;
        }
        tot += 1LL * -k * v;
    }
    
    for (int i = 0; i < n; ++i) {
    	std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
