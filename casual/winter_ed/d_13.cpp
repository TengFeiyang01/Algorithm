#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cmath>
#include <numeric>
#include <cstring>
#include <map>
#include <unordered_map>

using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, v[N];


void solve() {
    std::cin >> n;
    double avg = 0;
    double s = 0;

    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        avg += v[i];
    }
    avg = avg / n;

    for (int i = 0; i < n; ++i) {
        s += ((v[i] - avg) * (v[i] - avg));
    }
    s = s / n;

    for (int i = 0; i < n; ++i) {
        printf("%.16f\n", (v[i] - avg) / sqrt(s));
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
