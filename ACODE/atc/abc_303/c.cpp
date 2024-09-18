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
	std::string s;
    int n, m, h, k;
    std::cin >> n >> m >> h >> k;
    std::cin >> s;
    std::set<PII> st;
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	st.insert({x, y});
    }
    int x = 0, y = 0, ok = 1;
    for (auto c : s) {
    	h--;
        if (h < 0) {
            ok = 0;
        }
        if (c == 'R') {
    		x++;
    	} else if (c == 'L') {
    		x--;
    	} else if (c == 'U') {
    		y++;
    	} else {
    		y--;
    	}
    	if (st.count({x, y})) {
    		if (h < k) {
    			h = k;
    		    st.erase({x, y});
            }
    	}
    }
    std::cout << (ok ? "Yes" : "No");

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
