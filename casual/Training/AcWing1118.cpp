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
int n, ans = 11;
std::vector<int> a, st;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int g[11][11];

bool check(int group[], int gc, int i){
    for (int j = 0; j < gc; ++j)
        if (gcd(a[group[j]], a[i]) > 1)
            return false;
    return true;
}

void dfs(int u, int gc, int cnt, int start) {
    if (u >= ans) return;
    if (cnt == n) ans = u;
    bool f = 1;
    for (int i = start; i < n; ++i) 
        if (!st[i] && check(g[u], gc, i)) {
            st[i] = 1;
            g[u][gc] = i;
            dfs(u, gc + 1, cnt + 1, i + 1);
            st[i] = 0;
            f = 0;
        }

    if (f) dfs(u + 1, 0, cnt, 0);
}

void solve() {
    std::cin >> n;
    a.resize(n), st.resize(n);
    for (int i = 0; i < n; ++i) {
    	std::cin >> a[i];
    }


    dfs(1, 0, 0, 0);

    std::cout << ans << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    solve();

    return 0;
}
