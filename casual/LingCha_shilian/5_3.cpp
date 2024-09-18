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
    std::cin >> n;
    std::vector<std::array<int, 3>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0];
    }
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][1];
    	a[i][2] = i;
    }
    std::sort(a.begin(), a.end());
    std::vector<int> suf(n);

    //suf[i] = x 即前面的人只要能大于x 就可以赢得 [i, n-1]的所有人
    //     a b c d e
    //eg   4 8 3 6 5
    //suf  3 3 5 5 5 
    // 对于a这人而言 -> a > c -> c > b -> b->e -> e显然可以赢所有人
    
    suf[n - 1] = a[n - 1][1];
    int mn = a[n - 1][1];
    for (int i = n - 2; i >= 0; --i) {
    	mn = std::min(mn, a[i][1]);
    	if (a[i][1] > suf[i + 1]) {
    		suf[i] = mn;
    	} else {
    		suf[i] = suf[i + 1];
    	}
    }
    std::string ans(n, '1');
    int pre = 0;
    for (int i = 0; i < n - 1; ++i) {
    	pre = std::max(pre, a[i][1]);
    	if (pre < suf[i + 1]) {
    		ans[a[i][2]] = '0';
    	}
    }
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
