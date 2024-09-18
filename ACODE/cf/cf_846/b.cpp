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
#define all(x) bg(x) + 1, end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 2e5 + 13;
int mp[N + 1]{0};
std::vector<int> prime;

void solve() {
    int n;
    std::cin >> n;
    std::vector<ll> a(n + 1, 0LL);
    std::vector<ll> b(n + 1, 0LL);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        b[i] = b[i - 1] + a[i];
    }
    ll sum = b[n];
    ll ans = 1;
    ll t = 0;
    for (int i = 1; i < n; ++i) {
        sum -= a[i];
        t += a[i];
        ans = std::max(ans, std::__gcd(sum, t));
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    for (int i = 2; i < N; ++i) {
        if (!mp[i]) {
            mp[i] = i;
            prime.push_back(i);
        }
        for (auto p : prime) {
            if (i * p > N) break;
            mp[i * p] = p;
            //提前退出
            if (i % p == 0) break;
        }
    }

    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
