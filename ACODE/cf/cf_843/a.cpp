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

using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;
int n, m, nums[N];

void solve() {
    std::string s;
    std::cin >> s;
    //5 —— 123
    //1 
    for (int i = 1; i < s.size() - 1; ++i) 
        for (int j = i + 1; j < s.size(); ++j) {
            auto b = s.substr(i, j - i);
            auto c = s.substr(j);
            auto a = s.substr(0, i);
            if ((a <= b && c <= b) || (a >= b && c >= b)) {
                std::cout << a << " " << b << " " << c << "\n";
                return;
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
