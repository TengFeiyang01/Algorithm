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
int times[N];
ll cnt[N];

void solve() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) std::cin >> nums[i];
    int l, r;
    ll old = 0ll;
    std::cin >> m;
    for (int i = 1; i <= m; ++i) {
        std::cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }
    for (int i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];

    for (int i = 1; i <= n; ++i) old += (1LL * cnt[i] * nums[i]);
    std::sort(nums + 1, nums + n + 1);
    std::sort(cnt + 1, cnt + n + 1);
    ll New = 0; 
    for (int i = 1; i <= n; ++i) {
        New += nums[i] * cnt[i]; 
    }
    std::cout << New - old;
   
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t = 1;
    //std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
