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
    int n;

    std::cin >> n;
    std::vector<ll> a(n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        if (a[i] == 2) cnt++;
    }    
    if (cnt % 2 == 1) 
        std::cout << "-1\n";
    else {
        int t = cnt;
        for (int i = 1; i < n; ++i) {
            if (a[i] == 2) {
                t--;
            }
            if (t == cnt / 2) {
                std::cout << i << "\n";
                return;
            }
        }
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
