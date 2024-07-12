#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

struct DSU {
	std::vector<int> f, siz;
	DSU() {}
	DSU (int n_) {
		init(n_);
	}

	void init(int n) {
		f.resize(n);
		std::iota(f.begin(), f.end(), 0);
		siz.assign(n, 1);
	}

	int find(int x) {
		while (x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	bool merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		f[y] = x;
		siz[x] += siz[y];
		return true;
	}

	bool size(int x) {
		return siz[find(x)];
	}
};

void solve() {
    int n, m;
    std::cin >> n >> m;
    DSU uf(n * (n + 1));
    for (int i = 0; i < m; ++i) {
    	int x, y, a, b;
    	char op;
    	std::cin >> x >> y >> op;
    	--x, --y;
    	if (op == 'R') {
    		a = x * n + y;
    		b = a + 1;
    	} else {
    		b = (x + 1) * n + y;
    		a = x * n + y;
    	}
    	if (!uf.merge(a, b)) {
    		std::cout << i + 1 << "\n";
    		return;
    	}
    }
    std::cout << "draw";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
