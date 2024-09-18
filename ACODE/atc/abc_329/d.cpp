#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::map<int, int> freq;
    std::map<int, std::set<int>> cnt;
    int mx = 0;
    for (int i = 0; i < m; ++i) {
    	int x;
    	std::cin >> x;
    	cnt[freq[x]].erase(x);
    	cnt[++freq[x]].insert(x);
    	mx = std::max(mx, freq[x]);
    	std::cout << *cnt[mx].begin() << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
