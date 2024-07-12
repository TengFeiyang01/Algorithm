#include <bits/stdc++.h>
 
const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> d(n), f(n);
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	--x, --y;
    	d[y]++;
    }
    int cnt = 0, id = -1;
    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) {
            cnt++;
            id = i + 1;
        }
    }   
    std::cout << (cnt == 1 ? id : -1);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
