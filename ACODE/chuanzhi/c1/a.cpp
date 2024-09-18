#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> cnt;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i]]++;
    }
    std::vector<int> ans;
    for (auto x : a) {
    	if (cnt[x] == 1) {
    		ans.push_back(x);
    	}
    }
    std::cout << ans.size() << "\n";
    std::sort(ans.begin(), ans.end());
    for (auto x : ans ) {
    	std::cout << x << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
