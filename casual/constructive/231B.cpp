#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, d, l;
    std::cin >> n >> d >> l;
    int pos = (n + 1) / 2, neg = n / 2;
    if (d > pos * l - neg or d < pos - neg * l) {
    	std::cout << "-1\n";
    	return;
    }
    std::vector<int> a(n);

    //a[i] - pre = d ==> pre = a[i] - d
    for (int i = 0; i < n; ++i) {
        if (d > 0) {
            a[i] = l;
            d = a[i] - d;
        } else {
            a[i] = 1;
            d = a[i] - d;
        }
    }
    a[n - 1] -= d;
    for (int x : a) std::cout << x << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
