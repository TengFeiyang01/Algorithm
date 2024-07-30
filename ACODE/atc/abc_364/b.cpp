#include <bits/stdc++.h>
using i64 = long long;


void solve() { 
    int H, W, sx, sy;
    std::cin >> H >> W >> sx >> sy;
    std::vector<std::string> S(H);
    for (auto &s : S) {
        std::cin >> s;
    }
    std::string X;
    --sx, --sy;
    std::cin >> X;
    for (auto c : X) {
            if (c == 'L' and sy - 1 >= 0 and S[sx][sy - 1] == '.') {
                sy--;
            }
            if (c == 'R' and sy + 1 < W and S[sx][sy + 1] == '.') {
                sy++;
            }
            if (c == 'U' and sx - 1 >= 0 and S[sx - 1][sy] == '.') {
                sx--;
            }
            if (c == 'D' and sx + 1 < H and S[sx + 1][sy] == '.') {
                sx++;
            }

    }
    std::cout << sx + 1 << " " << sy + 1 << "\n";

}

int main() {
    std::ios::sync_with_stdio(0),std::cin.tie(0);
    
    solve();
    return 0;
}