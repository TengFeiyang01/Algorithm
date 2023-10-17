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
    int w[26];
    std::string s;
    std::cin >> s;
    int k;
    std::cin >> k;
    int mx = 0;
    for (int i = 0; i < 26; ++i) {
        std::cin >> m;
        w[i] = m;
        mx = std::max(mx, m);
    }
    ll ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        ans += (i + 1) * w[s[i] - 'a'];
    }
    int len = s.size();
    ++len;
    for (int i = 1; i <= k; ++i, ++len) {
        ans += len * mx;
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
