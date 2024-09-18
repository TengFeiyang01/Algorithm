#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    int x, y;
    std::cin >> x >> y;
    for (int i = 1; i < n; ++i) {
    	if ((a[i] == x and a[i - 1] == y) or (a[i] == y and a[i - 1] == x)) {
    		std::cout << "Yes\n";
    		return;
    	}
    } 
    std::cout << "No\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
