#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n), pos(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
        --a[i];
        pos[a[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
        b[i]--;
    }
    std::vector<int> f;
    for (int x : b) {
        x = pos[x];
        if (!f.size() or f.back() < x) f.push_back(x);
        else *std::ranges::lower_bound(f, x) = x;
    }
    std::cout << f.size() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
