#include <bits/stdc++.h>
using ll = long long;

const int N = 1e5 + 13;
ll f[N];
int n;

/*
    枚举每个收费cost, 那么总的收费为 num * (cost) num为 > cost 的人数 可以排序后二分
    时间复杂度O(nlogn)
*/

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> f[i];
    std::sort(f + 1, f + n + 1);
    ll res = 0, c = 0;
    for (int i = 1; i <= n; ++i) {
        int k = std::lower_bound(f + 1, f + n + 1, f[i]) - f;
        if ((n - k + 1) * f[i] > res) {
            res = (n - k + 1) * f[i];
            c = f[i];
        }
    }
    std::cout << res << " " << c;
    return 0;
}