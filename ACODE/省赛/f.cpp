#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<i64> a(n + 1), d(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
    	std::cin >> d[i];
    }

    const int lg = 23;
    std::vector<std::vector<i64>> f(n + 1, std::vector<i64>(lg)), g(n + 1, std::vector<i64>(lg)), nxt(n + 1, std::vector<i64>(lg));

    for (int i = 1; i <= n; ++i) {
    	f[i][0] = d[i];
    	g[i][0] = std::max(0LL, f[i][0]);
    	int j = std::lower_bound(a.begin(), a.end(), a[i] + k + 1) - a.begin();
    	if (j <= n) {
    		nxt[i][0] = j;
    	} else {
    		nxt[i][0] = 0;
    	}
    }

    
    for (int j = 1; j < lg; ++j) {
    	for (int i = 1; i <= n; ++i) {
    		f[i][j] = f[i][j - 1] + f[nxt[i][j - 1]][j - 1];
    		nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
	    	g[i][j] = std::max(g[i][j - 1], f[i][j - 1] + g[nxt[i][j - 1]][j - 1]); 
    	}
   	}

    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
    	i64 res = 0, ok = 0, p = i, s = 0LL, t = m;
    	for (int j = lg - 1; j >= 0; --j) {
    		if ((1 << j) <= t) {
    			t -= 1 << j;
    			if (!ok) {
    				ok = 1;
    				res = std::max(res, g[p][j]);
    			} else {
    				res = std::max(res, s + g[p][j]);
    			}
				s = s + f[p][j];   
				p = nxt[p][j];
    	    	ans = std::max(ans, res);
				if (p == 0) {
					break;
				}
    		}
    	}
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
