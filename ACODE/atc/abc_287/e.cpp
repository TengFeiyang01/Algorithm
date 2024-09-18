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
const int N = 6e5 + 13;

int son[N][26], cnt[N], idx, n; //下标是 0 的点即是根节点，又是空节点

void insert(std::string str) {
    int p = 0;
    for (int i = 0; i < sz(str); ++i) {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p]++;
    }
}

int query(std::string str) {
    int p = 0;
    int ans = 0;
    for (int i = 0; i < sz(str); ++i) {
        int u = str[i] - 'a';
        if (!son[p][u]) return ans;
        p = son[p][u];
        if (cnt[p] >= 2) ans = std::max(ans, i + 1);
    }
    return ans;
}

void solve() {
    int n;
    std::string s;
    std::cin >> n;
    std::vector<std::string> v;
    for (int i = 0; i < n; ++i) {
        std::cin >> s;
        v.pb(s);
        insert(s);
    }
    for (int i = 0; i < n; ++i) {
        int ans = query(v[i]);
        std::cout << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
