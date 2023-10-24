#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

int cnt = 1;
int f[N];

void solve() {
    int n;
    std::cin >> n;
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    //f[i]表示i朵花的最少花费
    for (int i = 1; i <= n; ++i) {
        f[i] = std::min(f[i], f[i - 1] + 1);
        for (int k = 2; k * i <= n; ++k) {
            //f[i/j]表示从i/j这个开始翻倍时的最小费用,
            //f[i/j]+4+(j-1)*2+i%(i/j)这就是翻倍后的通用的推导公式；

            f[k * i] = std::min(f[k * i], f[i] + 4 + 2 * (k - 1));
        }
    }

    std::cout << "Case #" << cnt++ << ": " << f[n] << "\n";
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
