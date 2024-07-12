#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n);
    i64 s = 0;
    for (i64 &x : a) {
    	std::cin >> x;
    	s += x;
    }
    int cnt = 0;
    i64 need = s / n, more = s % n, ans = 0;
    std::vector<i64> b(n, need);
    for (int i = n - 1; i >= 0 and more; --i, --more) b[i]++;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        ans += abs(a[i] - b[i]);
    }

    std::cout << ans / 2LL << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
