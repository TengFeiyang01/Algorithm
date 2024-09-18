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
    int loop_cnt = n / 2;
    
    std::vector<std::vector<char>> ans(n, std::vector<char>(n));


    std::string s = "+.";

    int sx = 0, sy = 0;
    int x = 0, y = 0;
    for (int i = 0; i < n / 2; ++i) {
    	char c = s[i % 2];
    	sx = x, sy = y;
    	for (; sy < n - i - 1; ++sy) ans[sx][sy] = c;
    	for (; sx < n - i - 1; ++sx) ans[sx][sy] = c;
    	for (; sy > i; --sy) ans[sx][sy] = c;
    	for (; sx > i; --sx) ans[sx][sy] = c;
    	loop_cnt++;
        x++, y++;
    }
    
    if (n % 2) {
        ans[n / 2][n / 2] = s[(n / 2) % 2];
    }

    for (auto s : ans) {
    	for (auto c : s) {
    		std::cout << c;
    	}
    	std::cout << "\n";
    }   
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
