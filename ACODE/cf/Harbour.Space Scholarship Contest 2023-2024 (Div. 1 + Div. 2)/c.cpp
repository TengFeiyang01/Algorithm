#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int x;
    std::cin >> x;
    std::vector<int> ans{x};
    
    while (x != (x & -x)) {
    	x -= x & -x;
    	ans.push_back(x);
    }

    while (x != 1) {
    	x -= x / 2;
    	ans.push_back(x);
    }
    std::cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
    	std::cout << ans[i] << " \n"[i == ans.size() - 1];
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