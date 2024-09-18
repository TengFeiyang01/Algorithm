#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e9 + 13;

void solve() {
	i64 x;
	std::cin >> x;
    std::vector<i64> a;
    i64 cur = 1;
    i64 t = 1;
    while (cur < N) {
    	a.push_back(cur);
    	t += 1;
    	cur += t;
    }
    bool ok = 0;
    for (int i = 0; i < a.size() and a[i] < x; ++i) {
        i64 need = x - a[i];
        if (*std::lower_bound(a.begin(), a.end(), need) == need) ok = 1;
    }
    std::cout << (ok ? "YES\n" : "NO\n");
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
