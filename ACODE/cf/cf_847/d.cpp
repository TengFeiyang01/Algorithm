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
    int n;
    std::map<ll, ll> mp;
    std::cin >> n;
    ll t;
    for (int i = 0; i < n; ++i) {
    	std::cin >> t;
    	mp[t]++;
    }
    int m = sz(mp);
    std::vector<int> d;
    t = 0;

    int la = 0;
    for (auto[x, y] : mp) {
        if (t == 0) {
            d.eb(y);
            t = 1;
            la = x;
        } else {
            if (la + 1LL != x) {
                d.eb(0);
                d.eb(y);
                la = x;
            } else {
                d.eb(y);
                la = x;
            }
        }
    }
    std::vector<int> a(sz(d), 0);
    a[0] = d[0];
    for (int i = 1; i < sz(d); ++i) {
    	a[i] = d[i] - d[i - 1];
    }
    int p = 0, q = 0;
    for (auto c : a) {
    	if (c > 0) p += c;
    	else q -= c;
    }
    std::cout << std::max(p, q) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
