#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <functional>
#include <vector>
#include <cstring>
#include <map>
#include <unordered_map>
#include <stack>
#include <numeric>
#include <cmath>
 
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
    int m, n;
    std::cin >> m >> n;
    std::vector a(m, std::vector<int>(n, 0));
    std::vector b(m, std::vector<int>(n, 1));
	std::vector<int> row(m), col(n);
    int ok = 1;
    for (int i = 0; i < m; ++i)
    	for (int j = 0; j < n; ++j) {
    		std::cin >> a[i][j];
    		if (a[i][j] == 0) {
				row[i] = 1;
                col[j] = 1;
    		} 
    	}

        for (int i = 0; i < m; ++i)
            if (row[i])
                for (int j = 0; j < n; ++j)
                    b[i][j] = 0;

        for (int i = 0; i < n; ++i)
            if (col[i])
                for (int j = 0; j < m; ++j)
                    b[j][i] = 0;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == 1) {
                int t = 0;
                for (int k = 0; k < m; ++k)
                    t += b[k][j];
                for (int k = 0; k < n; ++k)
                    t += b[i][k];
                if (t == 0) {
                    std::cout << "NO\n";
                    return;
                }
            }
        }



    std::cout << "YES\n";
	   for (int i = 0; i < m; ++i)
    	   for (int j = 0; j < n; ++j) 
    		  std::cout << b[i][j] << " \n"[j == n - 1];	


}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
