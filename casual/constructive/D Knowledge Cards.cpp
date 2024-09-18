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
const int N = 1e5 + 13;

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
    int n, m, k, x;
    std::cin >> n >> m >> k;

    Fenwick<int> tr(k);

    bool ok = true;
    for (int i = 0; i < k; ++i) {
        std::cin >> x;
        if (tr.sum(x - 1) >= n * m - 3) ok = false;
        tr.add(x - 1, 1);
    }
    if (ok) {
        std::cout << "YA\n";
    } else {
        std::cout << "TIDAK\n";
    }
}



// void solve() {
//     int n, m, k;
//     std::cin >> n >> m >> k;
    
//     std::vector<int> a(k);	
//     for (int i = 0; i < k; ++i) {
//     	std::cin >> a[i];
//     }

//     std::priority_queue<int> pq;
//     int cur = k;

//     int s = n * m - 3;
//     for (int v : a) {
//         //特判可以直接到达的情况
//     	if (v == cur and m + n == 4) {
//     		--cur;
//     		continue;
//     	}
//     	pq.push(v);
//     	if (pq.size() > s) {
//     		std::cout << "TIDAK\n";
//     		return;
//     	}
//     	while (pq.size() and pq.top() == cur) {
//     		--cur;
//     		pq.pop();
//     	}
//     }
//     std::cout << "YA\n";
// }

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
