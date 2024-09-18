#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;

    std::vector<int> ans(n, 1);
    int s = 1;
    //wa... 只有一个数的时候有解
    if (n == 1) {
        std::cout << 1 << "\n";
        return;
    }

    //没有 b 并且没有位置放 1 输出-1
    if (b == 0 and a == n - 1) {
        std::cout << "-1\n";
        return;
    }

    if (b) {
        for (int i = 1; i <= b; ++i) {
            ans[i] = s + 1;
            s += ans[i];
        }
    }
    if (a) {
        //如果没有 b 的话， 需要把第二位也置为1 这样第三位的 2 就不会产出b
        for (int i = b + 1 + (b == 0); i <= a + b + (b == 0); ++i) {
            ans[i] = ans[i - 1] + 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
