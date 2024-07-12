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
const int N = 2e5 + 13;

std::vector<int> f(N), cntv(N), cntd(N, 1);

int find(int x) {
    if (f[x] == x) {
        return f[x];
    } else {
        return f[x] = find(f[x]);
    }
}

void merge(int x, int y) { 
    x = find(x);
    y = find(y);
    if (x == y) cntv[x]++;
    else {
        f[x] = y;
        cntd[y] += cntd[x];
        cntv[y] += cntv[x] + 1;
    }
}

void solve() {
    int n, m, u, v;
    std::cin >> n >> m;
    for (int i = 0; i < N; ++i) {
        f[i] = i;
    }
    std::vector<int> cnt(n);
    for (int i = 0; i < m; ++i) {
    	std::cin >> u >> v;
    	u--, v--;
    	merge(u, v);
    }
    int ok = 1;
    for (int i = 0; i < n; ++i) {
        if (i == find(i) && cntv[i] != cntd[i]) {
            ok = 0;
        }
    }
    if (!ok)
    	std::cout << "No\n";
    else   std::cout << "Yes\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
