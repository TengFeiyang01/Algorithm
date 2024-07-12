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
    int n;
    std::string s;
    std::cin >> n >> s;
    std::vector<std::vector<int>> f(n, std::vector<int>(n, 0));

    for (int len = 1; len < n; ++len) {
    	for (int l = 0; l + len < n; ++l) {
    		int r = l + len;
    		if ((s[l] == '(' and s[r] == ')') or (s[l] == '[' and s[r] == ']'))
    			f[l][r] = f[l + 1][r - 1] + 2;
            //std::cout << l << " " << r << "\n";
    		for (int k = l; k < r; ++k)
    			f[l][r] = std::max(f[l][r], f[l][k] + f[k + 1][r]);
    	}
    }
    
    std::cout << f[0][n - 1];
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
