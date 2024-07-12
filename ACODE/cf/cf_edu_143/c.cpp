#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>

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
    int n;
    std::cin >> n;
    std::vector<ll> a(n);
    std::vector<ll> b(n);
    std::vector<ll> s(n);
    std::vector<ll> cnt(n + 1);
    std::vector<ll> remain(n + 1);
    for (ll&v : a) std::cin >> v;
    for (ll&v : b) std::cin >> v;

    s[0] = b[0];
    for (int i = 1; i < n; ++i) {
        s[i] += s[i - 1] + b[i];
    }

    ll pre = 0LL;
    for (int i = 0; i < n; ++i) {
        if (i) pre += b[i - 1];
        ll t = a[i] + pre;

        if (b[i] > a[i]) {
            remain[i] += a[i];
            continue;
        }

        int k = ub(all(s), t) - bg(s);
        cnt[i]++;
        cnt[k]--;
        if (s[k] != t) {
            remain[k] += t - s[k - 1];
        }
    }

    for (int i = 1; i <= n; ++i) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        std::cout << 1LL * (cnt[i] * b[i]) + remain[i] << " \n"[i == n - 1];
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