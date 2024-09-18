#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int H, W;
    std::cin >> H >> W;
    
    std::vector<std::string> c(H);
    for (int i = 0; i < H; i++) {
        std::cin >> c[i];
    }
    
    std::vector<int> cntr(H), cntc(W);
    std::vector<std::array<int, 26>> fr(H), fc(W);
    std::vector<int> disr(H), disc(W);
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cntr[i]++;
            cntc[j]++;
            int x = c[i][j] - 'a';
            disr[i] += !fr[i][x]++;
            disc[j] += !fc[j][x]++;
        }
    }
    
    int resr = H, resc = W;
    std::vector<bool> vis(H + W);
    std::queue<int> q;
    for (int i = 0; i < H; i++) {
        if (cntr[i] >= 2 && disr[i] == 1) {
            q.push(i);
        }
    }
    for (int i = 0; i < W; i++) {
        if (cntc[i] >= 2 && disc[i] == 1) {
            q.push(H + i);
        }
    }
    while (!q.empty()) {
        int i = q.front();
        q.pop();
        
        if (vis[i]) {
            continue;
        }
        vis[i] = true;
        if (i < H) {
            resr--;
            for (int j = 0; j < W; j++) {
                if (!vis[H + j]) {
                    int x = c[i][j] - 'a';
                    cntc[j]--;
                    disc[j] -= !--fc[j][x];
                    if (cntc[j] >= 2 && disc[j] == 1) {
                        q.push(H + j);
                    }
                }
            }
        } else {
            i -= H;
            resc--;
            for (int j = 0; j < H; j++) {
                if (!vis[j]) {
                    int x = c[j][i] - 'a';
                    cntr[j]--;
                    disr[j] -= !--fr[j][x];
                    if (cntr[j] >= 2 && disr[j] == 1) {
                        q.push(j);
                    }
                }
            }
        }
    }
    
    int ans = resr * resc;
    std::cout << ans << "\n";
    
    return 0;
}
