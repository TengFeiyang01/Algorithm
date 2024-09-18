#include <bits/stdc++.h>

using namespace std;

void solve() {
    int b, n, m;
    cin >> b >> n >> m;
    
    unordered_map<int, vector<pair<int, int>>> dic;
    for (int i = 0; i < n; ++i) {
        int group, v, w;
        cin >> group >> w >> v;
        dic[group].push_back({v, w});
    }
    
    vector<int> pa(m);
    vector<vector<int>> g(m);
    int root = -1;
    for (int i = 0; i < m; ++i) {
        cin >> pa[i];
        if (pa[i] == -1) {
            root = i;
        } else {
            g[pa[i]].push_back(i);
        }
    }
    
    vector<vector<int>> f(m, vector<int>(b + 1, 0));
    
    function<void(int)> dfs = [&](int x) {
        for (int y : g[x]) {
            dfs(y);
        }
        
        for (int j = b; j >= 0; --j) {
            for (int y : g[x]) {
                for (int k = j; k >= 0; --k) {
                    f[x][j] = max(f[x][j], f[x][j - k] + f[y][k]);
                }
            }
        }
        
        vector<int> q(b + 1, 0);
        for (auto& item : dic[x]) {
            int v = item.first;
            int w = item.second;
            for (int j = b; j >= v; --j) {
                q[j] = max(q[j], q[j - v] + w);
            }
        }
        
        vector<int> r(b + 1, 0);
        for (int v1 = 1; v1 <= b; ++v1) {
            for (int v2 = 0; v2 + v1 <= b; ++v2) {
                r[v1 + v2] = max(r[v1 + v2], q[v1] + f[x][v2]);
            }
        }
        
        f[x] = r;
    };
    
    dfs(root);
    
    int ans = *max_element(f[root].begin(), f[root].end());
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}
