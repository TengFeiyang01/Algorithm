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

//https://codeforces.com/problemset/problem/1742/F
//因为初始为a，因此一旦添加存在非a的字符串一定是YES，否则要比较长度，注意操作是叠加的。


void solve() {
    int n, k, op;
    std::cin >> n;
    std::string x;
    ll cnt[2] = {1, 1};
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        std::cin >> op >> k >> x;
        cnt[--op] += (ll) k * (ll)x.size();
        
        for (auto c : x) 
            if (c != 'a') 
                if (op) {
                    b = 1;
                } else {
                    a = 1;
                }

        if (b) {
            std::cout << "YES\n";
        } else if (a) {
            std::cout << "NO\n";
        } else {
            std::cout << ((cnt[0] >= cnt[1]) ? "NO\n" : "YES\n");
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
