#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	a[i]--;
    	if (a[i] == i) cnt++;
    }
    std::cout << (cnt + 1) / 2 << "\n";
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
