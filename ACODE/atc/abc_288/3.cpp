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
const int N = 2e5 + 13;
std::vector<std::vector<int>> g;
std::vector<int> st;

void dfs(int u) {
    st[u] = 1;
    for (auto v : g[u]) {
        if (!st[v]) dfs(v);
    }
}

void solve() {
    int n, m;
    std::cin >> n >> m;
    g.resize(n + 1);
    st.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!st[i]) {
            m++;
            dfs(i);
        }
    }
    std::cout << m - n << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
