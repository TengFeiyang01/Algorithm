#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::map<int, int> cnt;
    
    for (int &i : a) {
    	std::cin >> i;
    	cnt[i]++;
    }

    std::map<int, int> id;
    for (auto[x, y] : cnt) {
    	int p = 0;
    	while (p <= n) {
    		p += x;
    		id[p] += y;
    	}
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
    	ans = std::max(ans, id[i]);
    }
    std::cout << ans << "\n";
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
