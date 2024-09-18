#include <bits/stdc++.h>
using namespace std;
int f[51][51][51];
bool vis[51][51][51];
int T, n, m, k;
int dfs(int n, int m, int k) {
    if (n > m) return dfs(m, n, k);
    if (vis[n][m][k]) return f[n][m][k];
    vis[n][m][k] = true;
    if (k == 0 || n * m == k) return f[n][m][k] = 0;
    for (int i = 1; i <= n/2; i ++) {
        for (int j = 0; j <= min(i*m, k); j ++) {
            f[n][m][k] = min(f[n][m][k], dfs(i, m, j) + dfs(n-i, m, k-j) + m * m);
        }
    }
    for (int i = 1; i <= m/2; i ++) {
        for (int j = 0; j <= min(i*n, k); j ++) {
            f[n][m][k] = min(f[n][m][k], dfs(n, i, j) + dfs(n, m-i, k-j) + n * n);
        }
    }
    return f[n][m][k];
}
int main() {
    memset(f, 0x3f, sizeof(f));
    scanf("%d", &T);
    while (T --) {
        scanf("%d%d%d", &n, &m, &k);
        printf("%d\n", dfs(n, m, k));
    }
    return 0;
}
