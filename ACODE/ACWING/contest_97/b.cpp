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
    ll a, b, c, d, x;
    std::cin >> a >> b;
    ll s1 = 0, s2 = 0;

    for (int i = 0; i < a; ++i) {
    	std::cin >> x;
    	s1 = s1 * b + x;
    }
    std::cin >> c >> d;
    for (int i = 0; i < c; ++i) {
    	std::cin >> x;
    	s2 = s2 * d + x;
    }
    if (s1 == s2) {
    	std::cout << "=";
    } else if (s1 < s2) {
    	std::cout << "<";
    } else {
    	std::cout << ">";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
