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

void solve() {
    i64 a, b, c, k;
    std::cin >> a >> b >> c >> k;

    std::vector<i64> p(8, 1LL);
    for (int i = 1; i < 8; ++i) p[i] = p[i - 1] * 10;

    a--, b--, c--;
    
    // 枚举 A
    for (int i = p[a]; i < p[a + 1]; ++i) {
    	i64 x = std::max(p[b], p[c] - i);  // B 能取的最小值
    	i64 y = std::min(p[b + 1], p[c + 1] - i); // B 能取的最大值 + 1
    	if (x > y) continue;
    	if (y - x >= k) {
    		std::cout << i << " + " << x + k - 1 << " = " << i + k - 1 + x << "\n";
    		return;
    	} 
    	k -= y - x;
    }
    std::cout << "-1\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
