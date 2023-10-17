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
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::vector<int> od, ev;
    for (int i = 1; i <= n; ++i) {
        if (a[i] % 2 == 1) {
            od.pb(i);
        } else {
            ev.pb(i);
        }
    }
    int odd = sz(od);
    int eve = sz(ev);

    if (odd && odd <= 2 && eve >= 2) {
        std::cout << "YES\n";
        std::cout << od[0] << " " << ev[0] << " " << ev[1] << "\n";
    } else if (odd >= 3) {
        std::cout << "YES\n";
        std::cout << od[0] << " " << od[1] << " " << od[2] << "\n";
    } else {
        std::cout << "NO\n";
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
