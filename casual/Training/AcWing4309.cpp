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

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

// 求gcd目的 2 6| 4 12 // 除了之后都是  || 1, 3

void solve() {
    int n, x, y, a, b;
    std::cin >> n >> x >> y;
    std::set<PII> st;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a >> b;
        a -= x, b -= y;
        int t = gcd(a, b);
    	a /= t, b /= t;
        if (a < 0) a = -a, b = -b;
    	st.insert({a, b});
    }
    std::cout << st.size();
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
