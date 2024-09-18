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

#define all(x) bg(x), end(x)


void solve() {
    std::vector<int> v1{84,80,43,8,80,88,43,14,100,88};
    std::vector<int> v2{32,32,42,68,68,100,42,84,14,8};
    std::sort(all(v1));
    std::sort(all(v2));
    for (auto c : v1) std::cout << c << " ";
    std::cout << "\n";
    for (auto c : v2) std::cout << c << " ";
}


int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
