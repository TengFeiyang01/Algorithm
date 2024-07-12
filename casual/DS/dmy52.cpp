#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

template<typename T>
struct Tire {
    int idx = 1;
    struct node {
        int s[2], size;
    };
    std::vector<node> tr;
    const static int M = 31;

    Tire(int n) {
        tr.resize(n * 40);
    }
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

    T query(T x, T k) {
        int p = 1;
        T res = 0;
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
    Tire<int> tr(n);
    for (int i = 0, x; i < n; ++i) {
        std::cin >> x;
        tr.insert(x);
    }
    for (int i = 0; i < q; ++i) {
        int x, k;
        std::cin >> x >> k;
        std::cout << tr.query(x, k) << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
