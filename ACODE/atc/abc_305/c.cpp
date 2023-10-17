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

const int dirs[] = {-1, 0, 1, 0, -1};

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s[n];
    for (int i = 0; i < n; ++i) std::cin >> s[i];

    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#') continue;
    		int cnt = 0;
    		for (int k = 0; k < 4; ++k) {
    			int x = i + dirs[k], y = j + dirs[k + 1];
    			if (0 <= x and x < n and 0 <= y and y < m and s[x][y] == '#') cnt++;
    		}
    		if (cnt > 1) {
    			std::cout << i + 1 << " " << j + 1 << "\n";
    			return;
    		}
    	}
    }

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}

