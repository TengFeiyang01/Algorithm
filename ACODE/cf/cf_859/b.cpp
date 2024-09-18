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
    int n, s = 0, x, c;
    std::cin >> n;
    std::vector<int> a(n);
    std::priority_queue<int> q;

    int ec = 0;
    for (int i = 0; i < n; ++i) {
    	std::cin >> x;
    	s += x;
    	if (x % 2 == 0) ec += x;
    }
    if (ec > s - ec) {
    	std::cout << "YES\n";
    } else {
    	std::cout << "NO\n";
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
