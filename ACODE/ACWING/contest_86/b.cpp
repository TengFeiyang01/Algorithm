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
    ll ans = 1ll * n * n;
    std::set<int> row, col;
    for (int i = 0; i < m; ++i) {
        int x, y;
        std::cin >> x >> y;
        if (!row.count(x)) {
            row.insert(x);
        }

        if (!col.count(y)) {
            col.insert(y);
        }
        ll a = row.size(), b = col.size();
        std::cout << ans - n * (a + b) + (a * b) << " ";
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
