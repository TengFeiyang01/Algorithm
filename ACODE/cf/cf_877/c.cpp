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
    int n, m;
    std::cin >> n >> m;
    if (m % 2 == 0) {
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0, s = i * m + 1; j < m; ++j, ++s) {
    			std::cout << s << " \n"[j == m - 1];
    		}
    	}
    } else if (n % 2 == 0) {
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0, s = i + 1; j < m; ++j, s += n) {
   				std::cout << s << " \n"[j == m - 1];
    		}
    	}
    } else {
        for (int i = 0; i < n; i += 2)
            for (int j = 0, s = i * m + 1; j < m; ++j, ++s) {
                std::cout << s << " \n"[j == m - 1];
            }
        for (int i = 1; i < n; i += 2) {
            for (int j = 0, s = i * m + 1; j < m; ++j, ++s) {
                std::cout << s << " \n"[j == m - 1];
            }
        }

    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
