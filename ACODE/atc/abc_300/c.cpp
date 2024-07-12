#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
#define YES "YES\n"
#define Yes "Yes\n"
#define NO "NO\n"
#define No "No\n"
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;

std::vector<PII> get(int i, int j, int d) {
    std::vector<PII> ans{{i + d, j + d}, {i + d, j - d}, {i - d, j + d}, {i - d, j - d}};
    return ans;
}

void solve() {
    int H, W;
    std::cin >> H >> W;
    std::vector<std::string> C(H);
    int N = std::min(H, W);    
    for (int i = 0; i < H; ++i) std::cin >> C[i];
    std::vector<int> s(N + 1);
        
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) {
            int len = 0;
            for (int d = 1; d <= N; ++d) {
                bool ok = 1;
                for (auto[ni, nj] : get(i, j, d)) {
                    if (ni < 0 or nj < 0 or ni >= H or nj >= W) {
                        ok = 0;
                        break;
                    } else {
                        if (C[ni][nj] != '#') {
                            ok = 0;
                            break;
                        }
                    }
                }
                if (ok) {
                    len = d;
                }
            }
            s[len] += 1;
        }
        
    for (int i = 1; i <= N; ++i)
        std::cout << s[i] << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
