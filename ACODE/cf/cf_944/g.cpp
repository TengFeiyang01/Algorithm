#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, std::vector<int>> mp;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	mp[a[i] >> 2].emplace_back(a[i]);
    }

    for (auto &[_, v] : mp) {
    	std::ranges::sort(v);
    }
    
    for (int i = n - 1; i >= 0; --i) {
    	a[i] = mp[a[i] >> 2].back();
    	mp[a[i] >> 2].pop_back();
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
