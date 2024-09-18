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
    int n;
    std::cin >> n;
    std::vector<int> a(n), cost(n);
    std::vector pos(n + 1, std::vector<int>());
    
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    	pos[a[i]].push_back(i);
    }

    std::vector<i64> negSum(n + 1);
    for (int i = 0; i < n; ++i) {
    	std::cin >> cost[i];
    	negSum[i + 1] = negSum[i];
    	if (cost[i] < 0) {
    		negSum[i + 1] += cost[i];
    	}
    }

    int m;
    std::cin >> m;
    std::vector<int> b(m);
    for (int i = 0; i < m; ++i) {
    	std::cin >> b[i];
    }

    Fenwick<i64> tr(n);
    std::vector<i64> f(n, 1e18);
    i64 s = 0;

    for (int i = 0; i < n; ++i) {
    	if (a[i] > b[0]) {
    		if (cost[i] > 0) {
    			tr.add(i, cost[i]);
    		}
    	} else if (a[i] == b[0]) {
    		f[i] = s;
    	}
    	s += cost[i];
    }

    int pid = 1;
    // pid 指向待处理的下一个数 从小到大处理
    while (pid <= b[0]) ++pid;

    for (int bi = 1; bi < m; ++bi) {
    	auto p = pos[b[bi - 1]];
    	int j = 0, pre = -1;
    	i64 mn = 1e18;
    	for (auto i : pos[b[bi]]) {
    		if (pre >= 0) {
    			mn += tr.rangeSum(pre, i) + negSum[i] - negSum[pre];
    		}
    		while (j < p.size() and p[j] < i) {
    			i64 res = f[p[j]] + tr.rangeSum(p[j] + 1, i) + negSum[i] - negSum[p[j] + 1];
    			mn = std::min(mn, res);
    			++j;
    		}
    		f[i] = mn;
    		pre = i;
    	}
        // 将所有小于等于b[j-1]的数移除 这样计算大于b[j-1]的数的cost才是正确的
    	while (pid <= b[bi]) {
    		for (int i : pos[pid]) {
    			if (cost[i] > 0) {
    				tr.add(i, -cost[i]);
    			}
    		}
    		++pid;
    	}
    }
    i64 ans = 1e18;
    s = 0;
    for (int i = n - 1; i >= 0; --i) {
    	int v = a[i];
    	if (v == b[m - 1]) {
    		ans = std::min(ans, f[i] + s);
    	}
    	if (v > b[m - 1] or cost[i] < 0) {
    		s += cost[i];
    	}
    }
    if (ans >= 1e17) {
    	std::cout << "NO\n";
    } else {
    	std::cout << "YES\n" << ans << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
