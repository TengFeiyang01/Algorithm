#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve() {
    i64 n, d, k;
    cin >> n >> d >> k;
    i64 G = __gcd(n, d);
    k -= 1;
    i64 delta = n / G;
    i64 x = k / delta;
    k %= delta;
    cout << (x + k * d % n) % n << "\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout.setf(ios::fixed), cout.precision(8);

    int t;
    cin >> t;

    while (t --) {
        solve();
    }

    return 0;
}
