#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> v[i];
    }
    std::vector<std::set<int>> a(n);

    for (int i = 0; i < n - 1; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	--x, --y;
    	x = v[x];
    	y = v[y];
    	std::cout << x << " " << y << "\n";
    }

    int now = 0;
    while (1) {
    	if (a[now].count(now + 1)) {
    		now++;
    	} else {
    		break;
    	}
    }
    std::cout << now + 1 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
