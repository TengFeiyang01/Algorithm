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
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::map<ll, ll> cnt;
    std::vector<ll> a(n), b(m + 1);
    std::priority_queue<ll> pq1;
    std::priority_queue<ll> pq;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	cnt[a[i]]++;
    }

    for (int i = 1; i <= m; ++i) {
    	std::cin >> b[i];
        pq1.push(b[i]);
    }

    for (auto[x, y] : cnt) {
        pq.push(y);
    }

    ll ans = 0;
    while (pq1.size() > 0) {
        if (sz(pq) == 0) break;
        ll x = pq.top();
        pq.pop();
        ll t = pq1.top();
        pq1.pop();
        ans += std::min(x, t);
        if (x > t) {
            pq.push(x - t);
        }
    }

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
