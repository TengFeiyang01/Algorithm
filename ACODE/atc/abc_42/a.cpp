#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::vector<int> a(3);
    std::cin >> a[0] >> a[1] >> a[2];
    std::ranges::sort(a);
    if (a[1] == 5 and a[0] == 5 and a[2] == 7) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
