#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::vector<i64> w(n), f(n);
    std::iota(f.begin(), f.end(), 0);

    std::function<i64(i64)> find = [&](i64 x) {
    	if (f[x] == x) return x;
    	int p = f[x];
        f[x] = find(f[x]);
        w[x] += w[p];
    	return f[x];
    };

    i64 t = 0;
    for (int i = 0; i < q; ++i) {
    	int ty, l, r;
    	std::cin >> ty >> l >> r;
    	l = long(l + t) % n;
    	r = long(r + t) % n;

    	if (ty == 2) {
    		if (find(l) == find(r)) {
    			std::cout << w[l] - w[r] << "\n";
                t = std::abs(w[l] - w[r]);
    		}
    	} else {
    		i64 x;
    		std::cin >> x;
            int fl = find(l) , fr = find(r);
            if (fl != fr) {
                f[fl] = fr;
                w[fl] = -w[l] + w[r] + x;
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
