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
    std::vector<int> a(n + 1);
    std::vector<int> nxt(n + 1), id(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }   
    for (int i = 0; i <= n; ++i) 
    	id[i] = n + 1;
    for (int i = n; i >= 0; --i) {
    	nxt[i] = id[a[i]];
    	id[a[i]] = i;
    }

    int x = 0, y = 0;
    int ans = 0;
    for (int z = 1; z <= n; ++z) {
    	if (a[x] == a[z]) {
    		x = z;
    	} else if (a[y] == a[z]) {
    		y = z;
    	} else if (nxt[x] > nxt[y]) {
    		ans += 1;
    		x = z;
    	} else {
    		ans += 1;
    		y = z;
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
