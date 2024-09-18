#include <bits/stdc++.h>

struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
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
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[x] = y;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
	int n, ok = 1, f = 0;
	std::cin >> n;
	std::vector<int> b(n / 2);
	std::set<int> st;
	for (int i = 0; i < n / 2; ++i) {
		std::cin >> b[i];
		st.insert(b[i]);
		if (b[i] == 1) ok = 0;
		if (b[i] == n) f = 1;
	}
	if (st.size() * 2 != n or !ok or !f) {
		std::cout << "-1\n";
		return;
	} 

	DSU dsu(n + 1); 
	for (int x : b) {
		dsu.merge(x, x - 1);
	}
	
	std::vector<int> a(n);
	for (int i = 1 ; i < n; i += 2) {
		a[i] = b[i / 2];
	}
	for (int i = n - 2; i >= 0; i -= 2) {
		int v = dsu.find(a[i + 1]);
		if (v == 0) {
			std::cout << "-1\n";
			return;
		}
		dsu.merge(v, v - 1);
		a[i] = v;
	}
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << " \n"[i == n - 1];
	}
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
