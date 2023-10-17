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
const int N = 2e5 + 13;
int n, m;
int head[N], idx = 0;
struct e{
    int to, next;
}edge[N];

void add(int u, int v) {
    edge[idx].to = v;
    edge[idx].next = head[u];
    head[u] = idx++;
}

int color[N]{0};

bool dfs(int u, int c) {
    color[u] = c;
    for (int i = head[u]; ~i; i = edge[i].next) {
        int j = edge[i].to;
        if (!color[j]) {
            if (!dfs(j, 3 - c)) return false;
        } else {
            if (color[j] == c) return false;;
        }
    }
    return true;
}

void solve() {
    memset(head, -1, sizeof head);
    std::cin >> n >> m;
    while(m--) {
        int u, v;
        std::cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    bool f = true;
    for (int i = 1; i <= n; ++i) {
        if (!color[i]) {
            if (!dfs(i, 1)) {
                f = false;
                break;
            }
        }
    }
    if (f) {
        puts("Yes");
    } else {
        puts("No");
    }
    
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
