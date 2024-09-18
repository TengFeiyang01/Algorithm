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

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> mx(n + 2), mn(n + 2), dpmx(n + 2), dpmn(n + 2);

    dpmx[1] = dpmn[1] = mx[1] = 1;

    int cnt = 1;
    
    for(int i = 0; i < n; ++i) {
        char op;
        std::cin >> op;
        if (op == '+') {
            int v,x;
            std::cin >> v >> x;
            ++cnt;
            dpmx[cnt] = std::max(x, dpmx[v] + x);
            dpmn[cnt] = std::min(x, dpmn[v] + x);
            mx[cnt] = std::max(mx[v], dpmx[cnt]);
            mn[cnt] = std::min(mn[v], dpmn[cnt]);
        }
        else{
            int u, v, x;
            std::cin >> u >> v >> x;
            if(x >= mn[v] and x <= mx[v]) std::cout << "YES" << "\n";
            else std::cout << "NO\n";
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
