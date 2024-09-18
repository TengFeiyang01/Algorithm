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
    int n, s, r;
    std::cin >> n >> s >> r;
    int k = s - r;
    int avg = r / (n - 1);
    std::string ans(n, '0');
    for (int i = 0; i < n - 1; ++i) {
    	ans[i] += avg;
    }
    int mod = r % (n - 1);
    for (int i = 0; i < mod; ++i) {
    	ans[i]++;
    }
    ans[n - 1] += k;
    for (auto c: ans) {
    	std::cout << c << " ";
    }
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
