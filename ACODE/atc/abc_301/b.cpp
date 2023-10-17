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
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::cout << a[0] << " ";
    for (int i = 1; i < n; ++i) {
    	bool ok = 1;
    	if (abs(a[i] - a[i - 1]) == 1) {
    		std::cout << a[i] << " ";
    		continue;
    	} else {
    		ok = (a[i] - a[i - 1]) > 0;
    		if (ok) {
    			for (int j = a[i - 1] + 1; j < a[i]; ++j) {
    				std::cout << j << " ";
    			}
    		} else {
    			for (int j = a[i - 1] - 1; j > a[i]; --j) {
    				std::cout << j << " ";
    			}
    		}
            std::cout << a[i] << " ";
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
