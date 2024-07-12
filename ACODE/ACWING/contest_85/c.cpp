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
const int N = 1e3 + 13;
int n, m, nums[N];
int fa[N];

void init() {
    for (int i = 1; i <= N; ++i)
        fa[i] = i;
    return;
}

int find(int x) {
    //递归
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy)
        fa[fx] = fy;
}

void solve() {
    std::cin >> n >> m;
    init();
    for (int i = 1; i <= m; ++i) {
        int a, b;
        std::cin >> a >> b;
        merge(a, b);
    }

    ll ans = 1;
    std::map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        mp[find(i)]++;
    }
    for (auto[x, y] : mp) {
        ans <<= (y - 1);
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
 