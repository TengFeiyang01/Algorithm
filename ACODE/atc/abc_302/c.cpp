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
    std::string s[n];
    for (int i = 0; i < n; ++i) std::cin >> s[i];

    std::vector<int> st(n);

	bool ok = 0;	
	std::vector<int> path;
	std::function<void(int, int)> dfs = [&](int u, int state) {
	    if (path.size() == n) {
	    	for (int i = 0; i < n - 1; ++i) {
		    	int cnt = 0;
	    		for (int j = 0; j < m; ++j) {
	    			if (s[path[i]][j] != s[path[i + 1]][j]) {
	    				cnt++;
	    			}
	    		}
	    		if (cnt != 1) {
	    			return;
	    		}
	    	}
	    	ok = 1;
	        return;
	    }
	    for (int i = 0; i < n; ++i) {
	        if (!(state >> i & 1)) {
	            path.push_back(i);
	            dfs(i + 1, state | 1 << i);
	            //恢复现场
	            path.pop_back();
	        } 
	    }

	};
	dfs(0, 0);
	if (ok) {
		std::cout << "Yes\n";
	} else {
		std::cout << "No\n";
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
