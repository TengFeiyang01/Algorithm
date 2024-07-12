#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> pre(n + 1, -1), next(n + 1, n + 1);
    std::map<int, int> pos;
    for (int i = 1, x; i <= n; ++i) {
    	std::cin >> x; 
        pre[i] = pos[x];
    	next[pos[x]] = i;
    	pos[x] = i;
    }	
    std::function<bool(int, int)> split = [&](int l, int r) ->bool {
    	if (l >= r) return true;
    	for (int x = l, y = r; x <= y; x++, y--) {
    		if (pre[x] < l and r < next[x]) return split(l, x - 1) && split(x + 1, r);
    		if (pre[y] < l and r < next[y]) return split(l, y - 1) && split(y + 1, r);
    	}
    	return false;
    };
    if (split(1, n)) {
    	std::cout << "non-boring\n";
    } else {
    	std::cout << "boring\n";
    }
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