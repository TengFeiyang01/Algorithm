#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
 	int n;
 	std::cin >> n;
 	std::vector<std::array<int, 2>> port(n);
 	for (int i = 0; i < n; ++i) {
 		std::cin >> port[i][0];
 	}   

 	for (int i = 0; i < n; ++i) {
 		std::cin >> port[i][1];
 	}
 	std::sort(port.begin(), port.end(), [&](std::array<int, 2> x, std::array<int, 2> y){
 		return x[1] < y[1];
 	});
 	int k;
 	std::cin >> k;
 	int ans = 0;
 	for (int i = 0; i < n; ++i) {
 		int s = 0;
 		std::multiset<int> st;
 		for (int j = i; j < n; ++j) {
 			s += port[j][0];
 			st.insert(port[j][0]);
 			if (st.size() > k) {
 				s -= *st.begin();
 				st.erase(st.begin());
 			}
 		}
 		ans = std::max(ans, s * port[i][1]);
 	}
 	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
