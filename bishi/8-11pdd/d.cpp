#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);

    std::vector<int> cnt(n, -1);

    std::set<int> q;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::sort(a.begin(), a.end());

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
