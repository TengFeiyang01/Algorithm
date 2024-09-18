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
    int n;
    std::cin >> n;
    std::vector<int> a(n), suf(n + 1);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    suf[n] = a[n - 1];
    for (int i = n - 1; i >= 0; --i) {
    	suf[i] = std::max(suf[i + 1], a[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
    	std::cout << std::max(suf[i + 1] - a[i] + 1, 0) << " ";
    }
    std::cout << 0;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
