#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, std::vector<int>> a;
    for (int i = 0; i < 3 * n; ++i) {
    	int x;
    	std::cin >> x;
    	a[x - 1].push_back(i);
    }
    for (int i = 0; i < n; ++i) std::sort(a[i].begin(), a[i].end());
    std::vector<int> ans(n);
	std::iota(ans.begin(), ans.end(), 0);
	std::sort(ans.begin(), ans.end(), [&](auto x, auto y){
		return a[x][1] < a[y][1];
	});
	for (int x : ans) std::cout << x + 1 << " ";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
