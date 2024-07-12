#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    double p = 1;
    int n = 0;
    std::vector<double> a(8);
    for (int i = 1; i <= 7; ++i) {
        std::cin >> a[i];
        n += a[i];
    }
    std::cout << std::fixed << std::setprecision(3) << a[1]*1.0/n*a[2]/(n-1)*a[3]/(n-2)*a[4]/(n-3)*a[5]/(n-4)*a[6]/(n-5)*a[7]*5040;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
