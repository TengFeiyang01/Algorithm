#include <bits/stdc++.h>
 const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 30;
int f[N];

int l, r, mod;
int a[N];

int dp(int pos, bool is_limit, int ok) {
    if (pos == 0) return ok;
    if (!is_limit && ~f[pos] and ok) return f[pos];
    
    int ans = 0;
    if (!ok)
        ans += dp(pos - 1, false, false);

    int up = is_limit ? a[pos] : 9;
    for (int i : {4, 7}) {
        if (i <= up)
            ans += dp(pos - 1, is_limit && i == a[pos], true);
    }
    if (!is_limit and ok) f[pos] = ans;
    return ans;
}

ll calc(int n) {
    int idx = 0;
    memset(f, -1, sizeof f);
    while (n) a[++idx] = n % 10, n /= 10;
    return dp(idx, true, false);
}


void solve() {
    std::cin >> r;
    std::cout << calc(r);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
