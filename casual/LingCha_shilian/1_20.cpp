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
using vector = std::vector<std::vector<int>>;
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

/*
    https://codeforces.com/problemset/submission/1598/189793851

    提示 1：正难则反，考虑哪些不满足要求的选法。

    提示 2：如果选了三个横坐标相同的点，由于题目保证没有重复的点，所以三个纵坐标互不相同，这样是满足题目要求的。
           纵坐标同理，因此我们只能选恰好有两个横坐标相同的点，恰好有两个纵坐标相同的点。

    提示 3：这三个点组成了一个 L 型。

    提示 4：枚举每个点 (x,y) 作为 L 型的拐点，那么另外有 cntX[x]-1 个横坐标相同的点，cntY[y]-1 个横坐标相同的点。
           对答案的贡献是 (cntX[x]-1)*(cntY[y]-1)。
    答案为 C(n,3) - 这些贡献之和。
*/

void solve() {
    ll n;
    std::cin >> n;
    std::vector<PII> a(n);
   	std::unordered_map<int, int> Cntx, Cnty;
    for (auto&[x, y] : a) {
    	std::cin >> x >> y;
    	Cntx[x]++;
    	Cnty[y]++;
    }

    ll ans = n * (n - 1) * (n - 2) / 6LL;
    for (auto[x, y] : a) {
    	ans -= (Cnty[y] - 1LL) * (Cntx[x] - 1LL);
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
