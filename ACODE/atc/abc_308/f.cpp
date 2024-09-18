#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<i64> a(n);
    for (i64 &x : a) std::cin >> x;
    std::vector<std::array<int, 2>> b(m);
	for (int i = 0; i < m; ++i) std::cin >> b[i][1];
	for (int i = 0; i < m; ++i) std::cin >> b[i][0];
		
	std::priority_queue<std::array<int, 2>> pq;
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end(), [&](auto &x, auto &y){
		return x[1] < y[1];
	});
	i64 ans = 0;
	int i = 0;
	for (auto x : a) {
		while (i < m and b[i][1] <= x) {
			pq.push(b[i++]);
		}
		int discount = 0;
		
		if (pq.size()) {
			discount = pq.top()[0];
			pq.pop();
		}	
		ans += x - discount;
	}
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
