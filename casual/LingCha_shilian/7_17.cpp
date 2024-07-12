#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i) std::cin >> s[i];
    std::vector f(26, std::vector<int>(26, -inf));
		
	for (auto &str : s) {
		int v = str[0] - 'a', w = str.back() - 'a', len = str.size();
		for (int j = 0; j < 26; ++j) {
			f[j][w] = std::max(f[j][w], f[j][v] + len);
		}
		f[v][w] = std::max(f[v][w], len);
	}
	
	int ans = 0;
	for (int i = 0; i < 26; ++i) ans = std::max(ans, f[i][i]);
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
