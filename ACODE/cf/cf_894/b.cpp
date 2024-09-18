#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
    }
    std::vector<int> a{b[0]};
    for (int i = 1; i < n; ++i) {
    	if (b[i] < b[i - 1]) {
    		a.push_back(b[i]);
    		a.push_back(b[i]);
    	} else {
    		a.push_back(b[i]);
    	}
    }
    std::cout << a.size() << "\n";
    for (int i = 0; i < a.size(); ++i) {
    	std::cout << a[i] << " \n"[i == a.size() - 1];
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