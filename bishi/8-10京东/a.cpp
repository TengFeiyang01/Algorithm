#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n, t;
    std::cin >> n >> t;
    std::map<int, int> cnt;
    i64 ans = 0, res = 0;
    for (int i = 0; i < n; ++i) {
    	int x;
    	std::cin >> x;
    	ans += cnt[t - x];
    	if (x * 2 == t) {
    		res++;
    	}
    	cnt[x]++;
    }
    std::cout << (ans * 2 + res) << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
