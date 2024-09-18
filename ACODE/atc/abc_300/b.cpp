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
const int N = 1e5 + 13;

void solve() {
    int H, W;
    std::cin >> H >> W;
    std::vector<std::string> A(H);
    std::vector<std::string> B(H);
    for (int i = 0; i < H; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < H; i++) {
        std::cin >> B[i];
    }
    bool found = false;
    for (int s = 0; s < H && !found; s++) {
        for (int t = 0; t < W && !found; t++) {
            std::vector<std::string> shifted_A(H);
            for (int i = 0; i < H; i++) {
                shifted_A[i] = A[(i + s) % H].substr(t) + A[(i + s) % H].substr(0, t);
            }
            if (shifted_A == B) {
                found = true;
            }
        }
    }

    if (found) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
