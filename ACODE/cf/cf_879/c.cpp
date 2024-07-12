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

#if 0
void solve() {
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    int cnt = 0, rcnt = 0;
    for (int i = 0; i < n; ++i) {
    	cnt += s[i] != t[i];
    	rcnt += s[i] != t[n - i - 1];
    }

    if (cnt <= 1) {
    	std::cout << cnt << "\n";
    	return;
    } 
    if (rcnt <= 1) {
        std::cout << 2 << "\n";
        return;
    }

    std::function<int(int, int)> dfs = [&](int x, int y) ->int {
        if (x <= 1) return x;
        if (y <= 1) return 2;
        return 2 + dfs(y - 1, x - 1);
    };

    std::cout << dfs(cnt, rcnt) << "\n";
}
#endif

void solve() {
    int n;
    std::cin >> n;
    std::string s, t;
    std::cin >> s >> t;
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        x += s[i] != t[i];
        y += s[i] != t[n - i - 1];
    }
    std::cout << std::min(2 * x - x % 2, y ? (2 * y - (y + 1) % 2) : 2) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
