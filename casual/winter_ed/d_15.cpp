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
 
#define lb std::lower_bound
#define ub std::upper_bound
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, x, t, s;
    std::cin >> n >> x;
    std::vector<int> a(n), dp(500010, 0);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        s += a[i];
    }
    
    t = s - x;
    
    for (int i = 0; i < n; ++i) {
        int v = a[i];
        for (int j = t; j >= v; --j) {
            dp[j] = std::max(dp[j], dp[j - v] + v);
        }
    }
    
    std::cout << s - dp[t] << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
