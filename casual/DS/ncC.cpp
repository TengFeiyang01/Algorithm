#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int kth(T k) {
        int x = 0;
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};

void solve() {
    int n, c, m;
    std::cin >> n >> c >> m;
    std::vector<int> a(n);
    std::unordered_map<int, int> pos1, pos2;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::array<int, 3>> qry(m);
    for (int i = 0; i < m; ++i) {
        int l, r;
        std::cin >> l >> r;
        qry[i] = {r - 1, l - 1, i};
    }
    std::sort(qry.begin(), qry.end());
    std::vector<int> ans(m);
    Fenwick<int> tr(n);

    int j = 0;
    //我们不应该在第二次出现j的为位置上+1，而是在上一次出现的位置pos2[a[j]]上+1
    // eg: [2, 2, 3] 如果查询[2, 3] 此时在第二次出现加1的话(0, 1, 0) 答案为1 实际为0 
    // 应该在上一次出现的位置加1
    for (auto [r, l, id] : qry) {
        for (;j < n and j <= r; j++) {
            if (!pos2.count(a[j])) pos2[a[j]] = j;
            else {
                if (!pos1.count(a[j])) {
                    tr.add(pos2[a[j]], 1);
                    pos1[a[j]] = j;
                } else {
                    tr.add(pos1[a[j]], 1);
                    tr.add(pos2[a[j]], -1);
                    pos2[a[j]] = pos1[a[j]];
                    pos1[a[j]] = j;
                }
            }
        }
        ans[id] = tr.rangeSum(l, r + 1);
    }
    for (int i = 0; i < m; ++i) {
        std::cout << ans[i] << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
