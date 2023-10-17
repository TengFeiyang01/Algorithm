#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int t = (n + k - 1) / k;
    int x, cnt = 0, ok = 1;
    for (int i = 0; i < m; ++i) {
        std::cin >> x;
        if (x > t) {
            ok = 0;
        }
        if (x == t) {
            cnt++;
        }
    }
    //先分成 n / k 上取整组， 最后一组用最多的那几个涂，等于 n + k - 1 / k 的个数不应该超过 n % k
    //特别的 当n % k==0的时候 显然成立
    if (!ok) {
        std::cout << "NO\n";
    } else {
        if (cnt <= n % k or n % k == 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
