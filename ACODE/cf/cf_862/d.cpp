#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1e5 + 5;

int n;
vector<int> adj[MAXN];
int diameter, farthest;
int f[MAXN][MAXN], g[MAXN][MAXN], h[MAXN][MAXN];

void dfs(int u, int p) {
    f[u][0] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            for (int i = 0; i <= diameter; i++) {
                g[u][i] += g[v][i];
            }
        }
    }
    for (int i = 1; i <= diameter; i++) {
        for (int j = 0; j < i; j++) {
            f[u][i] += g[u][j] * f[u][i-j-1];
        }
    }
    for (int i = 0; i <= diameter; i++) {
        g[u][i] += f[u][i];
        h[u][i] = g[u][i];
    }
    for (int v : adj[u]) {
        if (v != p) {
            for (int i = 0; i <= diameter; i++) {
                g[u][i] -= g[v][i];
                for (int j = 0; j < i; j++) {
                    g[v][i-j-1] += g[v][j] * f[u][i-j-1];
                }
                g[u][i] += g[v][i];
            }
        }
    }
    if (g[u][diameter] > g[farthest][diameter]) {
        farthest = u;
    }
}

void solve(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            for (int i = 0; i <= diameter; i++) {
                g[v][i] = h[u][i] - g[v][i];
            }
            for (int i = 0; i <= diameter; i++) {
                for (int j = 0; j <= i; j++) {
                    f[v][i] -= g[v][j] * f[v][i-j-1];
                }
            }
            for (int i = 0; i <= diameter; i++) {
                g[v][i] = f[v][i];
            }
            for (int i = 0; i <= diameter; i++) {
                for (int j = 0; j < i; j++) {
                    g[v][i] += g[u][j] * f[v][i-j-1];
                }
            }
            for (int i = 0; i <= diameter; i++) {
                g[v][i] += g[u][i];
            }
            solve(v, u);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    diameter = g[farthest][diameter];
    solve(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << g[i][diameter] << " ";
    }
    cout << endl;
    return 0;
}