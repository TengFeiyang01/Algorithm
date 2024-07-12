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
    int n, k;
    std::cin >> n >> k;
    std::vector<std::array<int, 5>> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][3] = 1;
    }
    std::ranges::sort(a);
    Fenwick<i64> tr(k + 1);
    int top = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i][0] == a[top][0] and a[i][1] == a[top][1] and a[i][2] == a[top][2]) {
            a[top][3]++;
        } else {
            a[++top] = a[i];
        }
    }

    std::vector<std::array<int, 5>> tmp(n);

    std::function<void(int, int)> CDQ = [&](int l, int r) {
    	if (l == r) return;
    	int mid = l + r >> 1;
    	CDQ(l, mid); CDQ(mid + 1, r);
    	int i = l, j = mid + 1, k = l;
    	while (i <= mid or j <= r) {
    		if (j > r or (i <= mid and a[i][1] <= a[j][1])) tr.add(a[i][2], a[i][3]), tmp[k++] = a[i++];
            else a[j][4] += tr.sum(a[j][2] + 1), tmp[k++] = a[j++];
    	}
        for (i = l; i <= mid; ++i) tr.add(a[i][2], -a[i][3]);
    	for (i = l; i <= r; ++i) {
    		a[i] = tmp[i];
    	}
    };

    CDQ(0, top);
    
    std::vector<int> d(n);
    for (int i = 0; i <= top; ++i) {
        // 还要计算自身相同元素的贡献
        d[a[i][4] + a[i][3] - 1] += a[i][3];
    }

    for (int i = 0; i < n; ++i) {
    	std::cout << d[i] << " \n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
