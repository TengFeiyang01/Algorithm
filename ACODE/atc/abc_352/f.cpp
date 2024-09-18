#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;
    
    std::vector g(N, std::vector<int>(N));
    for (int i = 0; i < M; i++) {
        int A, B, C;
        std::cin >> A >> B >> C;
        A--, B--;
        g[A][B] = C;
        g[B][A] = -C;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (g[i][k] && g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
                }
            }
        }
    }
    
    std::vector<int> beg(N, 1);
    for (int i = 0; i < N; i++) {
        if (!beg[i]) {
            continue;
        }
        for (int j = 0; j < N; j++) {
            if (g[i][j]) {
                beg[j] = 0;
            }
        }
    }
    
    std::vector<int> min(N), max(N), mask(N);
    for (int x = 0; x < N; x++) {
        for (int i = 0; i < N; i++) {
            if (g[x][i] || i == x) {
                min[x] = std::min(min[x], g[i][x]);
                max[x] = std::max(max[x], g[i][x]);
            }
        }
        for (int i = 0; i < N; i++) {
            if (g[x][i] || i == x) {
                mask[x] |= 1 << (g[i][x] - min[x]);
            }
        }
    }
    
    for (int x = 0; x < N; x++) {
        std::vector<int> vis(N);
        for (int i = 0; i < N; i++) {
            if (g[x][i] || i == x) {
                vis[i] = 1;
            }
        }
        std::vector<int> dp(1 << N), f(1 << N, -1);
        f[(1 << N) - 1] = 0;
        
        int ans = -1;
        int cnt = 0;
        
        for (int s = (1 << N) - 1; s > 0; s--) {
            if (f[s] == -1) {
                continue;
            }
            int i = f[s];
            while (i < N && (vis[i] || !beg[i])) {
                i++;
            }
            if (i == N) {
                i = x;
                assert(__builtin_popcount(mask[x]) == __builtin_popcount(s));
            }
            for (int j = 0; j + max[i] - min[i] < N; j++) {
                int m = mask[i] << j;
                if ((s & m) == m) {
                    f[s ^ m] = i + 1;
                    if (i == x) {
                        ans = j - min[x] + 1;
                        cnt++;
                    }
                }
            }
        }
        if (cnt > 1) {
            ans = -1;
        }
        std::cout << ans << " \n"[x == N - 1];
    }
    
    return 0;
}
