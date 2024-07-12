#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a;

    int p = n - k + 1, q = 1;
    for (int i = 0; i < k; ++i) {
        a.push_back(p++);
        a.push_back(q++);
    }
    
    while (a.size() < n) {
        a.push_back(q++);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
