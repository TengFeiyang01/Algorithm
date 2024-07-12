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
    int n, s = 0, m = 1;
    std::cin >> n;
    int ne = 0;
    std::vector<int> a(n);
    for (int &x : a) {
    	std::cin >> x;
    	s += x;
    	if (x < 0) {
    		ne += 1;
    	}
    }
    int ans = 0;
    if (s < 0) {
    	ans += (abs(s) + 1) / 2;
    	ne -= ans;
    }
    if (ne > 0 and ne % 2) {
    	ans++;
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
