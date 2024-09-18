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

void solve() {
    int n, s1, s2;
    std::cin >> n >> s1 >> s2;
    int t1 = s1, t2 = s2;
    std::vector<PII> p(n);
    for (int i = 0; i < n; ++i) {
        auto&[x, y] = p[i];
        std::cin >> x;
        y = i + 1;
    }
    std::sort(p.begin(), p.end(), std::greater<PII>());
    std::vector<int> ans[2];
    for (auto[w, i] : p) {
        if (t1 < t2) ans[0].push_back(i), t1 += s1;
        else ans[1].push_back(i), t2 += s2;
    }
    for (int i = 0; i < 2; ++i) {
        std::cout << ans[i].size() << " ";
        for (auto x : ans[i]) std::cout << x << " ";
        std::cout << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
