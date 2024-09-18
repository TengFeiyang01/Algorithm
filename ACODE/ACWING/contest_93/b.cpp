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
using ll = unsigned long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n;
int ans = inf;

void dfs(ll cur, int step) {
    if (step > ans) return;
    std::vector<int> dig(10);
    ll t = cur, cnt = 0;
    while (cur) {
        cnt++;
        dig[cur % 10]++;
        cur /= 10;
    }
    if (step + n - cnt >= ans) return;

    if (cnt == n) {
        ans = std::min(ans, step);
    }

    for (ll i = 9; i >= 2; --i) {
        if (dig[i]) {
            dfs(i * t, step + 1);
        }
    }
}

void solve() {
    ll x;
    std::cin >> n >> x;  
    std::string s = std::to_string(x);
    if (sz(s) == n) {
        std::cout << "0";
        return;
    }
    if (std::count(all(s), '1') + std::count(all(s), '0') == sz(s)) {
        std::cout << "-1";
        return;
    }
    dfs(x, 0);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
