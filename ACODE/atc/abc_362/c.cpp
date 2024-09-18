#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
 	int n;
 	std::cin >> n;
 	std::vector<std::array<int, 2>> a(n);
 	i64 x = 0, y = 0;
 	std::vector<int> ans(n);
 	std::priority_queue<std::pair<int, int>> q;
 	for (int i = 0; i < n; ++i) {
 		std::cin >> a[i][0] >> a[i][1];
 		x += a[i][1];
 		y += a[i][0];
 		ans[i] = a[i][1];
 		q.push({a[i][1] - a[i][0], i});
 	}


 	if (y <= 0 && x >= 0) {
 		std::cout << "Yes\n";
 		while (x != 0) {
 			auto [v, p] = q.top();
 			q.pop();
 			if (x >= v) {
 				x -= v;
 				ans[p] -= v;
 			} else {
 				ans[p] -= x;
 				break;
 			}
 		}
 	} else {
 		std::cout << "No\n";
 		return;
 	}
 	for (int i = 0; i < n; ++i) {
 		std::cout << ans[i] << " \n"[i == n - 1];
 	}

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
