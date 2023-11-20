#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

const int N = 2e5 + 10;

struct Tire {
	int idx = 1;
	struct node {
		int s[2], size;
	}tr[N*32];

	const int M = 30;
	void insert(int x) {
		int p = 1;
		for (int i = M; i >= 0; --i) {
			int u = x >> i & 1;
			if (!tr[p].s[u]) {
				tr[p].s[u] = ++idx;
			}
			p = tr[p].s[u];
			tr[p].size++;
		}
	}

	int query(int x, int k) {
		int p = 1, res = 0;

		for (int i = M; i >= 0; --i) {
			int u = x >> i & 1;
			if (tr[tr[p].s[u]].size >= k) {
				p = tr[p].s[u];
			} else {
				k -= tr[tr[p].s[u]].size;
				p = tr[p].s[u ^ 1];
				res |= 1 << i;
			}
		}		
		return res;
	}
};

void solve() {
    int n, q;
    std::cin >> n >> q;
    std::cout << n << q << "\n";

    std::vector<int> a(n);
    Tire t;
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	t.insert(a[i]);
    }
    
    for (int i = 0; i < q; ++i) {
    	int x, k;
    	std::cin >> x >> k;
    	std::cout << t.query(x, k) << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
