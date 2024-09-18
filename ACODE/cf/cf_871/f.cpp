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
    int n, m;
    std::cin >> n >> m;
    std::vector<int> degree(n + 1);
    for (int i = 0; i < m; ++i) {
    	int a, b;
    	std::cin >> a >> b;
    	degree[a]++;
    	degree[b]++;
    }

    int z = 0;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 1) {
            z++;
        }    
    }

    std::cout << m - z << " " << z / (m - z) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    for (int i = 1; i <= t; ++i) solve();

    return 0;
}
