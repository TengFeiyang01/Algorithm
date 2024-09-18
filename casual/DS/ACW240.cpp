#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
constexpr int N = 3e5 + 13;

void solve() {
    int m;
    std::cin >> m;
    std::vector<int> d(N), f(N), siz(N, 1);
    std::iota(f.begin(), f.end(), 0);

    std::function<int(int)> find = [&](int x) {
    	if (f[x] != x) {
    		int rt = find(f[x]);
    		d[x] += d[f[x]];
    		f[x] = rt;
    	}
    	return f[x];
    };

    for (int i = 0; i < m; ++i) {
    	char op;
    	int x, y;
    	std::cin >> op >> x >> y;
    	int fx = find(x), fy = find(y);
    	if (op == 'M') {
    		if (fx != fy) {
    			f[fx] = fy;
    			d[fx] = siz[fy];
    			siz[fy] += siz[fx];
    		}
    	} else {
    		if (fx != fy) {
    			std::cout << "-1\n";
    		} else {
    			std::cout << std::max(0, std::abs(d[x] - d[y]) - 1) << "\n";
    		}
    	}
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
