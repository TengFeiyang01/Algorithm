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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n), b(m), c(n + m);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	c[i] = a[i];
    }
    for (int j = 0; j < m; ++j) {
    	std::cin >> b[j];
    	c[j + n] = b[j];
    }
    std::map<int, int> mp;
    std::sort(all(c));
    for (int i = 0; i < n + m; ++i) {
    	mp[c[i]] = i + 1;
    }
    for (int i = 0; i < n; ++i) {
    	std::cout << mp[a[i]] << " \n"[i == n - 1];
    }
    for (int i = 0; i < m; ++i) {
    	std::cout << mp[b[i]] << " ";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
