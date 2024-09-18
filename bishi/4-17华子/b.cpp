#include <bits/stdc++.h>

using namespace std;
int tot = 0;
int cnt[2][100000];
vector<int> adj[100000];
set<int> root, node;
int d[100000];

void solve() {
    int m, n;
    cin >> m >> n;
    map<string, int> id;


    for (int i = 0; i < n; i++) {
            string x, y;
            int l, v;
            cin >> x >> y >> l >> v;
            if (!id.count(x)) {
                    id[x] = ++tot;
            } 
            if (y == "*") {
                    root.insert(id[x]);
            }
            if (!id.count(y) && y != "*") {
                    id[y] = ++tot;
            }
            if (y != "*") {
                    d[id[y]]++;
                    adj[id[x]].push_back(id[y]);
            }
            cnt[l][id[x]] = v;
            node.insert(id[x]);
    }

    int ans = 0;

    queue<int> q;
    for (int x : node) {
            if (d[x] == 0) {
                    q.push(x);
            }
    }

    while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : adj[u]) {
                    cnt[0][v] += cnt[0][u];
                    cnt[1][v] += cnt[1][u];
                    if (--d[v] == 0) {
                            q.push(v);
                    }
            }
    }

    for (auto u : root) {
        if (cnt[0][u] * 5 + cnt[1][u] * 2 > m) {
                ans++;
        }   
    }

    std::cout << ans << "\n";
    
}

int main() {
    
    solve();

    return 0;
}
