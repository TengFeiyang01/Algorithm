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
    ll a, b, c;
    int s;
    int k = 2;
    a = 1, b = 0, c = 0;
    std::cin >> s;
    s -= 1;
    while (s > 0) {
        int ok = 0;
        int t = 2;
        while (t--) {
            if (s >= k) {
                s -= k;
                b += k++;
            } else {
                b += s;
                ok = 1;
                break;
            }
        }
        if (ok) break; 
        t = 2;
        while (t--) {
            if (s >= k) {
                s -= k;
                a += k++;
            } else {
                a += s;
                ok = 1;
                break;
            }
        }
        if (ok) break;
    }

    std::cout << a << " " << b << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
