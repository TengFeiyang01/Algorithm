#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }
    std::map<int, int> cnt;

    std::vector<int> pre(n), suf(n);
    std::vector<int> f;
    for (int i = 0; i < n; ++i) {
    	if (f.empty() || f.back() < a[i]) {
    		f.push_back(a[i]);
    		pre[i] = f.size();
    	} else {
    		auto j = std::ranges::lower_bound(f, a[i]) - f.begin();
    		pre[i] = j + 1;
    		f[j] = a[i];
    	}
    }
    f.clear();

    for (int i = n - 1; i >= 0; --i) {
    	if (f.empty() || f.back() < -a[i]) {
    		f.push_back(-a[i]);
    		suf[i] = f.size();
    	} else {
    		auto j = std::ranges::lower_bound(f, -a[i]) - f.begin();
    		suf[i] = j + 1;
    		f[j] = -a[i];
    	}
    }
    int len = f.size();
    f.clear();
    std::vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
    	if (pre[i] + suf[i] - 1 == len) {
    		ans[i] = 3;
    		cnt[pre[i]]++;
    	} else {
    		ans[i] = 1;
    	}
    }
    for (int i = 0; i < n; ++i) {
    	if (ans[i] == 3 and cnt[pre[i]] > 1) {
    		ans[i] = 2;
    	}
    	std::cout << ans[i];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}

template<typename T>
struct Tire {
    int idx = 1;
    struct node {
        int s[2],size;
    };
    std::vector<node> tr;
    Tire(int n) {
        tr.resize(n * 30);
    }

    const static int M = 30;
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

    int query(T x, int k) {
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