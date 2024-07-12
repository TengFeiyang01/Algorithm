#include <bits/stdc++.h>
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define eb emplace_back
 
#define lb std::lower_bound
#define ub std::upper_bound
const int inf = 0x3f3f3f3f;
using ll = long long;
using PII = std::pair<int, int>;
const int N = 4e5 + 13;

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

struct node {
    int l, r, id;
    bool operator<(const node& b) const {
        return (l != b.l) ? l < b.l : r < b.r;
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<node> a(n);
    std::vector<int> b(n * 2);
    for (int i = 0; i < n; ++i) {
    	int x, y;
    	std::cin >> x >> y;
    	a[i] = {x, y, i};
    	b[i << 1] = x;
    	b[i << 1 | 1] = y;
    }
    std::sort(all(b));
    Fenwick<int> f(N);
    int k = std::unique(all(b)) - b.begin();

    auto ls = [&](int x) ->int {
    	return std::lower_bound(all(b), x) - b.begin();
    };
    for (int i = 0; i < n; ++i) {
        a[i].l = ls(a[i].l);
        a[i].r = ls(a[i].r);
    }
    std::sort(all(a));

    for (int i = 0; i < n; ++i) {
    	f.add(a[i].r, 1);
    }

    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
    	f.add(a[i].r, -1);
    	ans[a[i].id] = f.sum(a[i].r);
    }
    for (auto& v: ans) {
    	std::cout << v << "\n";
    }


}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
