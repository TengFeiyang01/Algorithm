#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 2e3 + 3;
vector<int> g[maxn];
bool vis[maxn];
 
int bfs(int x) {
    memset(vis, false, sizeof(vis));
    int ans = 0;
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while (q.size()) {
        int t = q.front();
        q.pop();
        for (auto it: g[t]) {
            if (!vis[it]) {
                vis[it] = true;
                ans++;
                q.push(it);
            }
        }
    }
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += bfs(i);
    }
    cout << ans - m << endl;
    return 0;
}