#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b;
    for (int &x : a) {
    	std::cin >> x;
    	if (b.empty() or b.back() < x) {
    		b.push_back(x);
    	} else {
    		*std::lower_bound(b.begin(), b.end(), x) = x;
    	}
    }
    std::cout << b.size() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
