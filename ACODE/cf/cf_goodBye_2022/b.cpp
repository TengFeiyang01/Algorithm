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

const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];

void solve() {
    std::cin >> n >> m;
    std::vector<int> v;
    for (int i = 0; i < n / 2; ++i) {
        v.push_back(n - i);
        v.push_back(i + 1);
    }
    if (n % 2) v.push_back(n / 2 + 1);
    for (int i : v) std::cout << i << " ";
    std::cout << "\n"; 
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
