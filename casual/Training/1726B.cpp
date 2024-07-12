#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    if (m < n) {
    	std::cout << "NO\n";
    	return;
    }
    std::vector<int> a(n, 1);
    if (n % 2) {
    	a[n - 1] = m - n + 1;
    } else {
    	int t = m - n + 2;
    	if (t % 2) {
    		std::cout << "NO\n";
    		return;
    	} else {
    		a[n - 2] = t / 2;
    		a[n - 1] = t / 2;
    	}
    }
    std::cout << "YES\n";
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