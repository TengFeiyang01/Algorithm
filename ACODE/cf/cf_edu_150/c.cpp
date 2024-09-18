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
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

i64 dp[200100][2][5];

constexpr int p[] = {1, 10, 100, 1000, 10000};

/*
void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();

    for (int x = 0; x < 5; ++x) dp[n][0][x] = dp[n][1][x] = 0;

    for (int i = n - 1; i >= 0; --i) {
    	for (int j = 0; j < 2; ++j) {
    		for (int x = 0; x < 5; ++x) {
    			dp[i][j][x] = -1e13;
    		}
    		for (int c = 0; c < 5; ++c) {
    			int k = j - (c != (s[i] - 'A'));
    			if (k >= 0) {
    				for (int x = 0; x < 5; ++x) {
    					if (c < x) {
    						dp[i][j][std::max(c, x)] = std::max(dp[i][j][std::max(x, c)], dp[i + 1][k][x] - p[c]);
    					} else {
    						dp[i][j][std::max(c, x)] = std::max(dp[i][j][std::max(x, c)], dp[i + 1][k][x] + p[c]);
    					}
    				}
    			}
    		}
    	}
    }
    i64 ans = -1e13;
    for (int x = 0; x < 5; ++x) {
    	ans = std::max({ans, dp[0][0][x], dp[0][1][x]});
    }
    std::cout << ans << "\n";
}
*/


void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();

    int id[5][2];
    memset(id, -1, sizeof id);
    for (int i = 0; i < n; ++i) {
        if (id[s[i] - 'A'][0] == -1) {
            id[s[i] - 'A'][0] = i;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (id[s[i] - 'A'][1] == -1) {
            id[s[i] - 'A'][1] = i;
        }
    }

    auto check = [&](int i, int op, int k) ->i64 {
        int x = id[i][op];
        if (x == -1) return -1e13;
        char o = s[x];
        s[x] = 'A' + k;
        i64 ans = 0;
        char mx = 'A';
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] < mx) {
                ans -= p[s[i] - 'A'];
            } else {
                ans += p[s[i] - 'A'];
            }
            mx = std::max(mx, s[i]);
        }
        s[x] = o;
        return ans;
    };
    i64 ans = -1e13;
    for (int i : {0, 1})
        for (int j : {0, 1, 2, 3, 4}) 
            for (int k : {0, 1, 2, 3, 4})
                ans = std::max(ans, check(j, i, k));
    std::cout << ans << "\n";
} 

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
