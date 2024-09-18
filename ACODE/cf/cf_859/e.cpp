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

using std::endl;

void solve() {
    int n;
    std::cin >> n;
    ll sum = 0;
    //初始n堆石子 每一堆的默认重量是a[i] 有一堆是a[i] + 1  找出那一堆
    std::vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
    	std::cin >> a[i];
    	sum += a[i];
        a[i] += a[i - 1];
    }


    auto ask = [&](int l, int r) -> ll {
        std::cout << "? " << r - l + 1 << " ";
        for (int i = l; i <= r; ++i) {
            std::cout << i << " ";
        }
        std::cout << endl;
        std::cout << endl;
        fflush(stdout);

        ll res;
        std::cin >> res;
        return res;
    };

    int l = 1, r = n + 1;
    while (l < r) {
        int mid = l + r >> 1;
        ll x = ask(l, mid);
        //默认每一堆是1  查询的和默认的不等于说明在左边
        if (a[mid] - a[l - 1] != x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    std::cout << "! " << r << endl;
    std::cout << endl;
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve();
        fflush(stdout);
    }

    return 0;
}
