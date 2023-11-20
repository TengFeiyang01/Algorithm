#include <bits/stdc++.h>
 
template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n = 0) {
        init(n + 1);
    }
    
    void init(int n) {
        this->n = n;
        a.assign(n, T());
    }
    
    void add(int x, T v) {
        for (int i = x; i <= n; i += i & -i) {
            a[i] += v;
        }
    }
    
    T sum(int x) {
        auto ans = T();
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

void solve() {
    int n = 10;
    Fenwick<int> a(n);
    a.add(1, 1);
    a.add(2, 1);
    a.add(3, 1);
    a.add(5, 1);
    a.add(10, 1);
    std::cout << a.sum(6) << "\n";
    std::cout << a.sum(4) << "\n";
    std::cout << a.rangeSum(1, 10);
    std::cout << a.rangeSum(2, 10);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
