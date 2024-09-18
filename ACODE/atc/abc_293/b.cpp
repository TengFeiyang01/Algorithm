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
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1, 0);
    std::vector<int> b(n + 1, 1);

    for (int i = 1; i <= n; ++i) {
        int x;
        std::cin >> x;
        if (a[i]) continue;
        else {
            a[x] = 1;
            b[x] = 0;
        }
    }
    std::vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (b[i]) 
            ans.push_back(i);
    }
    std::cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i)
        std::cout << ans[i] << " \n"[i == sz(ans)];

} 

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
