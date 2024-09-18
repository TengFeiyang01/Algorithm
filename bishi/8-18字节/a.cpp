#include <bits/stdc++.h>

using namespace std; 

int main() {
    
    int n;
    string s;
    cin >> n >> s;
    
    vector<bool> vis(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    function<int(int,int)> dfs;
    dfs = [&](int u, int fa) {
        vis[u] = true;
        int r = 1;
        for (int v: g[u]) {
            if (v == fa) continue;
            if (s[v] == 'W') continue;
            r += dfs(v, u);
        }
        return r;
    };
    
    int p = 0;
    function<int(int,int,int)> dfs2;
    dfs2 = [&](int u, int fa, int gz) {
        int x = 0;
        int r = 1;
        for (int v: g[u]) {
            if (v == fa) continue;
            if (s[v] == 'W') continue;
            int tmp = dfs2(v, u, gz);
            
            r += tmp;
            x = max(x, tmp);
        }
        x = max(x, gz - r);
        p = min(x, p);
        return r;
    };
    
    
    vector<array<int, 2>> list;
    for (int i = 0; i < n; i++) {
        if(!vis[i] && s[i] == 'R') {
            int z = dfs(i, -1);
            p = z;
            dfs2(i, -1, z);
            list.push_back({z, p});
        }
    }
    
    
    int fv = -1, fi = -1;
    int sv = -1, si = -1;
    
    int ans = 0;
    for (int i = 0; i < list.size(); i++) {
        auto &e = list[i];
        if (fv < e[0]) {
            sv = fv; si = fi;
            fv = e[0];
            fi = i;
        } else if (sv < e[0]) {
            sv = e[0];
            si = i;
        }  
        ans = max(ans, e[0]);
    }

    for (int i = 0; i < list.size(); i++) {
        auto &e = list[i];
        if (i != fi) {
            ans = min(ans, max(fv, e[1]));
        } else {
            ans = min(ans, max(sv, e[1]));
        }
    }
    
    cout << ans << '\n';
        
    return 0;
}