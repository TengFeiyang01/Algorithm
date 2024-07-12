#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::map<int, int> cnt, rcnt;
    for (int i = 0; i < m; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	cnt[x + y]++;
    	rcnt[x - y]++;
    }
    std::cout << cnt.size() << " " << rcnt.size() << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
