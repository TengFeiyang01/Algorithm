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
    int n, k;
    std::cin >> n >> k;
    std::string s[n];
    // int ans = n;
    // for (int i = 0; i < n; ++i) {
    // 	std::cin >> s[i];
    //     if (s[i] != s[0]) {
    //         ans--;
    //     }
    // }
    int ans = 0;
    std::map<std::string, int> cnt;
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        cnt[s[i]] += 1;
        ans = std::max(ans, cnt[s[i]]);
    } 
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
