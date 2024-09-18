#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

template<typename T>
struct Tire {
    int idx = 1;
    struct node {
        int s[2],size;
    };
    std::vector<node> tr;
    Tire(int n) {
        tr.resize(n * 32);
    }

    const static int M = 32;
    void insert(T x) {
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

    T query(T x, int k) {
        int p = 1;
        T res = 0;

        for (int i = M; i >= 0; --i) {
            int u = x >> i & 1;
            if (tr[p].s[u ^ 1]) {
                if (tr[tr[p].s[u ^ 1]].size >= k) {
                    res |= 1LL << i;
                    u ^= 1;
                } else {
                    k -= tr[tr[p].s[u ^ 1]].size;
                }
            }
            p = tr[p].s[u];
        }       
        return res;
    }
};

struct info {
	i64 val, i, x;
	bool operator<(const info &other) const {
		return val < other.val;
	}
};

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n + 1);
    Tire<i64> t(n + 1);

    t.insert(0LL);
    std::priority_queue<info> pq;
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	a[i] ^= a[i - 1];
        t.insert(a[i]);
    }
    for (int i = 0; i <= n; ++i) {
        pq.emplace(t.query(a[i], 1LL), i, 1);
    }
    
    i64 ans = 0;
    for (k *= 2; k > 0; --k) {
    	auto[val, i, x] = pq.top();
        pq.pop();
    	x++;
    	ans += val;
    	val = t.query(a[i], x);
    	pq.emplace(val, i, x);
    }
    std::cout << ans / 2 << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
