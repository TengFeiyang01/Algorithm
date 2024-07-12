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
const long long p = 998244353;

ll qmi(ll a, ll k, ll p) {
    ll res = 1;
    while (k) {
        if (k & 1) res = (ll)res * a % p;
        k >>= 1;
        a = (ll)a * a % p;
    }
    return res;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector a(n + 1, std::vector<int>(2, 0));
    std::vector dp(n + 1, std::vector<long long>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i][0] >> a[i][1];
    }
    for (int i = 2; i <= n; ++i) {
        if (a[i][0] != a[i - 1][0]) {
            dp[i][0] = (dp[i][0] + dp[i - 1][0]) % p;
        }
        if (a[i][0] != a[i - 1][1]) {
            dp[i][0] = (dp[i][0] + dp[i - 1][1]) % p;
        }

        if (a[i][1] != a[i - 1][0]) {
            dp[i][1] = (dp[i - 1][0] + dp[i][1]) % p;
        }
        if (a[i][1] != a[i - 1][1]) {
            dp[i][1] = (dp[i - 1][1] + dp[i][1]) % p;
        }
    }
	std::cout << (dp[n][0] + dp[n][1]) % p;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
