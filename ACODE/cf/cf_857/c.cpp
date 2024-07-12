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
const int N = 300;

void solve() {
    int n, m;
    std::cin >> n >> m;
    int cur = 0;
    std::vector a(N, std::vector<int>(N));
    std::cout << n * m << "\n";
    a[1][1] = 8;
    a[1][2] = 9;
    a[2][1] = 10;
    a[2][2] = 11;
    for (int i = 1; i <= 2; ++i)
    	for (int j = 3; j <= m; ++j)
    		a[i][j] = a[i][j - 2] + 4;

    for (int i = 3; i <= n; ++i)
    	for (int j = 1; j <= m; ++j)
    		a[i][j] = a[i - 2][j] + 512;


    for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= m; ++j) 
    		std::cout << a[i][j] << " \n"[j == m];
    	

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
