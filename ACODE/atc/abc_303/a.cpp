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
    std::string s, t;
    std::cin >> n >> s >> t;
    int ok = 1;
    for (int i = 0; i < n; ++i) {
    	if (s[i] != t[i]) {
    		if (s[i] == 'l' and t[i] == '1' or s[i] == '1' and t[i] == 'l') {
    			continue;
    		} else if (s[i] == '0' and t[i] == 'o' or s[i] == 'o' and t[i] == '0') {
    			continue;
    		} 
    		ok = 0;
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
 