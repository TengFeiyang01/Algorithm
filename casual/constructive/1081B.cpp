#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, std::vector<int>> pos;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	a[i] = n - a[i];
    	pos[a[i]].push_back(i);
    }
    int t = 1;
    std::vector<int> ans(n);
    for (int i = 0; i <= n; ++i) {
    	if (pos[i].size() and (pos[i].size() % i) != 0) {
    		std::cout << "Impossible\n";
    		return;
    	}
    	for (int j = 0; j < pos[i].size(); j += i) {
    		for (int k = 0; k < i; ++k) ans[pos[i][j + k]] = t;
    		t++;
    	}
    }
    std::cout << "Possible\n";
    for (int x : ans) std::cout << x << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
