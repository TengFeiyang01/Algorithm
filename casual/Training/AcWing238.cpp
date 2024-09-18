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
const int N = 3e4 + 13;
std::vector<int> d(N, 0);

struct DSU {
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1) { std::iota(f.begin(), f.end(), 0); }
    int leader(int x) {
        if (f[x] != x) {
            int rt = leader(f[x]);
            d[x] += d[f[x]];
            f[x] = rt;
        }
        return f[x];
    }
    bool same(int x, int y) { return leader(x) == leader(y); }
    void merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x != y) {
            f[x] = y;
            d[x] = siz[y];
            siz[y] += siz[x];
        }
    }
    int size(int x) { return siz[leader(x)]; }
};

void solve() {
    int m, x, y;
    DSU dj(N + 1);
    std::string s;
    std::cin >> m;
    while (m--) {
        std::cin >> s >> x >> y;
        if (s[0] == 'M') {
            dj.merge(x, y);
        } else {
            if (dj.same(x, y)) std::cout << std::max(0, abs(d[y] - d[x]) - 1) << "\n";
            else std::cout << "-1\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
