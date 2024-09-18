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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1), b(n + 1);
    for (int i = 0; i < m; ++i) {
    	int t, id;
    	std::cin >> t >> id;
    	if (t == 1) {
    		a[id]++;
    	} else if (t == 2) {
    		b[id]++;
    	} else {
    		if (a[id] >= 2 || b[id] >= 1) {
    			std::cout << "Yes\n";
    		} else {
    			std::cout << "No\n";
    		}
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
