#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    i64 n, m, k;
    std::cin >> n >> m >> k;
    std::string s;
    std::cin >> s;
    std::vector<int> pos;
    for (int i = 0; i < n; ++i) {
    	if (s[i] == 'x') {
    		pos.push_back(i);
    	}
    }
    
    int cntX = pos.size();
    
    i64 ans = std::min(k / cntX * n + pos[k % cntX], m * n);

	for (auto p : pos) {    
    	k++;
    	i64 res = std::min(k / cntX * n + pos[k % cntX], m * n) - p - 1;
    	ans = std::max(ans, res);
    }
    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}