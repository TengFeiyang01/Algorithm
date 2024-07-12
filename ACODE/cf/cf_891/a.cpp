#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int odd = 0, even = 0;
    for (int &x : a) {
    	std::cin >> x;
    	if (x % 2) odd++;
    	else even++;
    }
    if (n == 2 and odd == even) {
    	std::cout << "NO\n";
    	return;
    }
    if (odd % 2) {
    	std::cout << "NO\n";
    	return;
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
