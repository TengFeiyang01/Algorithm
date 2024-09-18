#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

//最小异或对 只在排序后相邻产生

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::array<int, 2>> a(n);
    std::vector<i64> b(n);
    i64 ans = 1e18;
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i];
        a[i][0] = b[i];
        a[i][1] = i;
    }
    std::sort(a.begin(), a.end());
    int l = 0, r = 0;

    for (int i = 0; i < n - 1; ++i) {
        if ((a[i][0] ^ a[i + 1][0]) < ans) {
            ans = (a[i][0] ^ a[i + 1][0]);
            l = a[i][1];
            r = a[i + 1][1];
        }
    }

    //它两或起来是0的位置 x 这个位置需要是1 否则是0
    std::cout << l + 1 << " " << r + 1 << " " << ((b[l] | b[r]) ^ ((1 << k) - 1)) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
