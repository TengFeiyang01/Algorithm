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
    std::sort(a.begin(), a.end());

    std::vector<int> st(n);
    std::vector<int> ans{n - 1};
    st[n - 1] = 1;
    int cur = a[n - 1];

    while (true) {
        int id = -1, mx = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (!st[i] and ((a[i] | cur) - cur) > mx) {
                mx = (a[i] | cur) - cur;
                id = i;
            }
        }
        if (mx == 0 or mx == -1) break;
        ans.push_back(id);
        st[id] = 1;
        cur |= a[id];
    }
    for (auto i : ans) std::cout << a[i] << " ";
    for (int i = 0; i < n; ++i) {
        if (!st[i]) {
            std::cout << a[i] << " ";
        }
    }
    std::cout << "\n";
}
int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
