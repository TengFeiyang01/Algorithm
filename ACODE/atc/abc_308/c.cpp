#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<i64, 3>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1];
    	a[i][2] = i + 1;
    }
    std::stable_sort(a.begin(), a.end(), [&](auto &x, auto &y){
    	return (y[0] + y[1]) * (x[0]) > (x[0] + x[1]) * y[0];
    });
    for (auto &x : a) std::cout << x[2] << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
