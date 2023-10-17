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
    std::vector<int> b(n);
    bool one = 0, two = 0;
    int ans = inf;
    std::vector<std::string> a(n);

    std::set<int> c1, c2;
    for (int i = 0; i < n; ++i) {
    	std::cin >> b[i] >> a[i];
    	if (a[i][0] == '1' and a[i][1] == '1') {
            ans = std::min(b[i], ans);
        }
        if (a[i][0] == '1') {
    		one = true;
    		if (a[i][1] == '0') {
	    		c1.insert(b[i]);
    		}
    	}
    	if (a[i][1] == '1') {
    		two = true;
			if (a[i][0] == '0') {
	    		c2.insert(b[i]);
			}
    	}
    }


    if (one and two) {
    	if (c1.size() and c2.size()) {
            ans = std::min(ans, *c1.begin() + *c2.begin());
        }
    	std::cout << ans << "\n";
    } else {
    	std::cout << "-1\n";
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
