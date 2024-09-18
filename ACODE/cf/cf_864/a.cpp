#include <bits/stdc++.h>


#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

int dirs[] = {-1, 0, 1, 0, -1};

void solve() {
    int n, m, x1, y1, x2, y2;
    std::cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x1 + dirs[i], ny = y1 + dirs[i + 1];
        if (nx < 1 || nx > n || ny < 1 || ny > m)
            s1++;
        nx = x2 + dirs[i], ny = y2 + dirs[i + 1];
        if (nx < 1 || nx > n || ny < 1 || ny > m)
            s2++;
    }
    int ans = 4;
    ans -= std::max(s1, s2);
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
