#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n, n), l(n), r(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> l[i];
    	a[i] -= l[i];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> r[i];
    	a[i] -= r[i];
    }

    int ok = 1;

    for (int i = 0; i < n; ++i) {
    	int x = a[i], cnt = 0;
    	for (int j = 0; j < i; ++j) {
    		if (a[j] > x) cnt++;
    	}
    	if (cnt != l[i]) {
    		ok = 0;
    	}
    	cnt = 0;
    	for (int j = i + 1; j < n; ++j) {
    		if (a[j] > x) cnt++;
    	}
    	if (cnt != r[i]) ok = 0;
    }
    if (ok) {
    	std::cout << "YES\n";
    	for (int x : a) std::cout << x << " ";
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
