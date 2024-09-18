#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::array<int, 3>> a(Q);
    for (auto &[x, y, z] : a) {
    	std::cin >> x >> y >> z;
        --x, --y;
    }

    std::vector<i64> fa(N), d(N);
    std::iota(fa.begin(), fa.end(), 0);

    std::function<int(int)> find = [&](int x) {
    	if (x != fa[x]) {
    		int root = find(fa[x]);
    		d[x] += d[fa[x]];
    		fa[x] = root;
    	}
    	return fa[x];
    };

    int i = 1;
    for (auto &[x, y, z] : a) {
    	int fx = find(x), fy = find(y);
    	if (fx != fy) {
    		d[fx] = d[y] - d[x] + z;
    		fa[fx] = fy;
    		std::cout << i << " ";
    	} else if (d[x] - d[y] == z) {
    		std::cout << i << " ";
    	}
    	i++;
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
