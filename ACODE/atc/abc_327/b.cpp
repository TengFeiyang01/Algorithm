#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

i64 qpow(i64 x, i64 y) {
    i64 res = 1;
    for (; y; y /= 2, x = x * x)
        if (y & 1)
            res = res * x;
    return res;
}
void solve() {
    i64 a, b;
    std::cin >> b;
    a = 1;
    while (qpow(a, a) < b) {
    	a++;
    }
    if (qpow(a, a) == b) {
    	std::cout << a;
    } else {
    	std::cout << -1;
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
