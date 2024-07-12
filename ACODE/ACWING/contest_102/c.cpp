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
    int n;
    ll k;
    std::cin >> n >> k;
    
    std::vector<ll> a(n);
    std::unordered_map<ll, ll> cnt1, cnt2;
    
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        cnt2[a[i]]++;
    }

    ll ans = 0;
    if (k == 1) {
        for (auto[x, y] : cnt2) {
            ans += 1LL * y * (y - 1LL) * (y - 2LL) / 6;
        }
        std::cout << ans;
        return;
    }
    
    for (int i = 0; i < n; ++i) {
        cnt2[a[i]] -= 1;
        if (a[i] % k == 0 and cnt1[a[i] / k] > 0 and cnt2[1LL * a[i] * k] > 0) {
            ans += cnt1[a[i] / k] * cnt2[a[i] * k] * 1LL;
        }
        cnt1[a[i]] += 1;
    }

    std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
