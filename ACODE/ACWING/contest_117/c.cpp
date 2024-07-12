#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
	int n;
	std::cin >> n;
	int cnt = -1;
    std::map<std::string, int> deep;
    deep["bessie"] = 1;
    int ans = 1;

    for (int i = 0; i < n; ++i) {
    	std::string a, b;
    	std::cin >> a >> b;
    	for (auto &c : a) {
    		c = tolower(c);
    	}
    	for (auto &c : b) {
    		c = tolower(c);
    	}
    	deep[a] = deep[b] + 1;
    	ans = std::max(ans, deep[a]);
    }
    std::cout << ans << "\n";

}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
