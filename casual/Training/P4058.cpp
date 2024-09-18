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
using ull = unsigned long long;
using ll = unsigned long long;
using PII = std::pair<int, int>;
const int N = 2e5 + 13;

void solve() {
    ull n, s, L;
    std::cin >> n >> s >> L;
    std::vector<ull> h(n), a(n);
    for (int i = 0; i < n; ++i) std::cin >> h[i];
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    auto check = [&](ull k)->bool{
        ull sum = 0;
        for (int i = 0; i < n; ++i) {
            ll t = h[i] + a[i] * k;
            if (t >= L) {
                sum += t;
            }
        }
        return sum >= s;
    };

    ull l = 0, r = 1e18;
    while (l < r) {
        ull mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    std::cout << l;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
