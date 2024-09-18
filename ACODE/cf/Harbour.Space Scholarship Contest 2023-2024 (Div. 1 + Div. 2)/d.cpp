#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> A(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> A[i];
    	A[i] = " " + A[i];
    }

    std::vector l(n + 2, std::vector<int>(n + 2, 0)), r = l, d = l, val = l;
    int ans = 0;
    //每次操作是等腰梯形 采用打标记方法
    
    for (int i = 1; i <= n; ++i) {
    	for (int j = 1; j <= n; ++j) {
    		if (l[i][j]) {
    			val[i][j] ^= 1;
    			l[i + 1][j - 1] ^= 1;
    			d[i + 1][j] ^= 1;
    		} 
    		if (d[i][j]) {
    			val[i][j] ^= 1;
    			d[i + 1][j] ^= 1;
    		} 
    		if (r[i][j]) {
    			val[i][j] ^= 1;
    			r[i + 1][j + 1] ^= 1;
    			d[i + 1][j] ^= 1;
    		}
    		int x = A[i][j] - '0';
    		if (x ^ val[i][j]) {
    			ans++;
    			l[i + 1][j - 1] ^= 1;
    			d[i + 1][j] ^= 1;
    			r[i + 1][j + 1] ^= 1;
    		}
    	}
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}