#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;
	int n = s.size() - 1;
	int cnt = 0;
	for (auto c : s) cnt += c != '0';
	std::cout << cnt << "\n";
	for (auto c : s) {
		if (c != '0') {
			std::cout << std::string(1, c) + std::string(n, '0') << " ";
		}
		--n;
	}
	std::cout << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}