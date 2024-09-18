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
const int N = 1513;

int head[N], idx;
struct e{
    int to, next;
}edge[N];

void add(int u, int v) {
    edge[idx].to = v;
    edge[idx].next = head[u];
    head[u] = idx++;
}
int st[N];
int f[N][2];

void solve() {
    int n;
    while (scanf("%d", &n) != -1) {
        memset(head, -1, sizeof head);
        memset(st, 0, sizeof st);
        memset(f, 0, sizeof f);
        idx = 0;
        for (int i = 0; i < n; ++i) {
            int u, cnt;
            scanf("%d:(%d)", &u, &cnt);
            while (cnt--) {
                int v;
                scanf("%d", &v);
                add(u, v);
                st[v] = 1;
            }
        }

        int root = 0;
        while (st[root]) root++;

        //std::function<void(int)> dfs = [&](int u) {
        auto dfs = [&](auto &self, int u)->int {
            f[u][1] = 1;
            f[u][0] = 0;
            for (int j = head[u]; ~j; j = edge[j].next) {
                int v = edge[j].to;
                //dfs(v);
                self(self, v);
    
                f[u][0] += f[v][1];
                f[u][1] += std::min(f[v][1], f[v][0]);
            }
        };
    
        //dfs(root);
        dfs(dfs, root);
        printf("%d\n", std::min(f[root][1], f[root][0]));
        /*std::cout << std::min(f[root][1], f[root][0]);*/
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();
    
    return 0;
}
