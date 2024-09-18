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
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    ll n, m;
    std::cin >> n >> m;
    ll b[n + 1];
    for (int i = 1; i <= n; ++i) {
    	std::cin >> b[i];
    }
    auto check = [&](int k) ->bool {
        ll t = m;
        ll a[n + 1];
        for (int i = 1; i <= k; ++i) {
            a[i] = b[i];
        }
        std::sort(a + 1, a + k + 1);
        for (int i = k; i > 0; i -= 2) {
            t -= a[i];
        }
        return t >= 0;
    };

    ll l = 2, r = n;

    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }

    std::cout << std::min(n, l); 
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
