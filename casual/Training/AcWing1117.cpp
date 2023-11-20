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
    std::vector<int> used(n);
    std::vector g(n, std::vector<int>(n));
    std::vector<std::string> word(n);
    for (int i = 0; i < n; ++i) std::cin >> word[i];
    char start; std::cin >> start;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			std::string a = word[i], b = word[j];
			for (int k = 1; k < std::min(sz(a), sz(b)); ++k)
				if (a.substr(sz(a) - k) == b.substr(0, k)) {
					g[i][j] = k;
					break;
				}
		}
	int ans = 0;
	std::function<void(std::string, int)> dfs = [&](std::string dragon, int last) {
		ans = std::max(ans, sz(dragon));
		used[last]++;

		for (int i = 0; i < n; ++i)
			if (g[last][i] && used[i] < 2) 
				dfs(dragon + word[i].substr(g[last][i]), i);
		//恢复现场
		used[last]--;
	};


	for (int i = 0; i < n; ++i)
		if (word[i][0] == start)
			dfs(word[i], i);
	std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
