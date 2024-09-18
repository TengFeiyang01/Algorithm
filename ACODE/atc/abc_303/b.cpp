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
    int n, m;
    std::cin >> n >> m;
    std::vector a(m, std::vector<int>(n));
    std::vector st(n, std::vector<int>(n));
    for (auto& row : a) {
    	for (int &x : row) {
    		std::cin >> x;
    		x--;
    	}
    }
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			st[a[i][j]][a[i][j + 1]] = 1;
			st[a[i][j + 1]][a[i][j]] = 1;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (st[i][j] == 0) ans++;
		}
	}
	std::cout << ans;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
