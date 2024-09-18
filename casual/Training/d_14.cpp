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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> c(n + 1, 1), a(n + 1), b(n + 1);

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 1; i <= n; ++i) c[i] = c[i - 1] * a[i];

    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        b[i] = (m % c[i] - sum) / c[i - 1];
        sum = m % c[i - 1];
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << b[i] << " \n"[i == n];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
