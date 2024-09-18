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

    long long f(long long x) {
        long long ans = 0ll;
        for (x /= 5;x != 0;x /= 5)
            ans += x;
        return ans;
    }

    int preimageSizeFZF(int k) {
        long long l = 4ll * k, r = 5ll * k;
        while (l < r) {
            const long long m = (l + r) / 2;
            if (f(m) < k)
                l = m + 1;
            else r = m;
        }

        if (f(l) == k) {
            std::cout << 5 << "\n";
            for (int i = l; i < l + 5; ++i)
                std::cout << i << " ";
        } else {
            std::cout << 0;
        }
        return f(l) == k ? 5 : 0;
    }
void solve() {
    ll n;
    std::cin >> n;
    preimageSizeFZF(n);
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
