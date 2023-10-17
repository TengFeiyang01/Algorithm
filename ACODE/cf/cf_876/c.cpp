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
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    if (a[n - 1] == 1) {
    	std::cout << "NO\n";
    	return;
    }
    int cnt = 0;
    std::cout << "YES\n";
    std::vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 1) {
            cnt++;
            if (i == 0 or a[i - 1] == 0)
                ans[i] = cnt;
        } else {
            cnt = 0;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        std::cout << ans[i] << " \n"[i == 0];
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
