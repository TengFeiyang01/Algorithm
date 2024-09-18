#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, cnt = -1;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    int mx = *std::max_element(a.begin(), a.end());
    for (int x : a) {
        if (x == mx) cnt++;
    }
	if (a[0] == mx and !cnt) std::cout << 0;
	else std::cout << mx + 1 - a[0];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
