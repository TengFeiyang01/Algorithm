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
    int g[n + 1][n + 1];
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n - 1; ++j) {
            std::cin >> g[i][j];
        }
    }
    int cnt[n + 1]{0};
    for (int i = 1; i <= n; ++i) {
        cnt[g[i][1]]++;
    }
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == n - 1) {
            std::cout << i << " ";
            t = i;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (g[i][1] != t) {
            for (int j = 1; j < n; ++j) {
                std::cout << g[i][j] << " \n"[j == n - 1];
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
