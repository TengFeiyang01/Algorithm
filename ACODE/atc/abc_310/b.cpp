#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> p(n);
    std::vector<std::bitset<100>> f(n);
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> p[i];
    	std::cin >> x;
    	while (x--) {
    		int k;
    		std::cin >> k;
    		k--;
    		f[i][k] = 1;
    	}
    }
    bool ok = false;
    for (int i = 0; i < n; ++i)
    	for (int j = 0; j < n; ++j) {
    		if (i == j) continue;
    		if (p[i] < p[j]) continue;
    		if ((f[i] & f[j]) != f[i]) continue;
    		if (p[i] > p[j] or f[i] != f[j]) ok = true;
    	}
    if (ok) {
    	std::cout << "Yes\n";
    } else {
    	std::cout << "No\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
