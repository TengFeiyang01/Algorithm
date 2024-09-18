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
using PII = std::pair<ll, int>;
const int N = 1e5 + 13;

void solve() {
    int n, k, dif = 0;
    std::cin >> n >> k;
    int kkk = (n - 1) % (k - 1);
    if (kkk) dif = k - 1 - kkk;
    std::priority_queue<PII, std::vector<PII>, std::greater<PII> > pq;
    for (int i = 0; i < n; ++i) {
        ll a;
        std::cin >> a;
        pq.emplace(a, 1);
    }
    for (int i = 0; i < dif; ++i) pq.emplace(0LL, 1);
    ll ans = 0;
    int len = 0;
    
    while (sz(pq) > 1) {
        ll t = 0ll;
        for (int i = 0; i < k; ++i) {
            auto [v, h] = pq.top();
            len = std::max(len, h);
            pq.pop();
            t += v;
        }
        ans += t;
        pq.emplace(t, len + 1);
    }
    std::cout << ans << "\n" << len;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
