#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), cnt(51);
    for (int &x : a) {
    	std::cin >> x;
    	while (x > n) x >>= 1;
    	cnt[x]++;
    }
    for (int i = n; i > 0; --i) {
    	if (cnt[i] == 0) {
    		std::cout << "NO\n";
    		return;
    	}
    	while (cnt[i] > 1) cnt[i / 2]++, cnt[i]--;
    }
    for (int i = 1; i <= n; ++i) {
    	if (cnt[i] == 0) {
    		std::cout << "NO\n";
    		return;
    	}
    }
    std::cout << "YES\n";
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
