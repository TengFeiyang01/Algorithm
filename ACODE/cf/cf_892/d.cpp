#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> a(n);
    for (int i = 0; i < n; ++i) {
    	int l, r, x, y;
    	std::cin >> l >> r >> x >> y;
    	a[i] = {l, y};  //l能跳到y 如果大于y没必要跳
    }
    std::sort(a.begin(), a.end());
    std::vector<std::array<int, 2>> b;

    //合并区间板子
    int st = -inf, ed = -inf;
    for (auto [L, R] : a) {
    	if (ed < L) {
    		if (ed != -inf) b.push_back({st, ed});
    		st = L;
    		ed = R;
    	} else if (ed < R) {
    		ed = R;
    	}
    }
    if (st != -inf and ed != -inf) b.push_back({st, ed});
    

    int q;
    std::cin >> q;
    while (q--) {
    	int x;
    	std::cin >> x;
    	int pos = std::upper_bound(b.begin(), b.end(), std::array<int, 2>({x, inf})) - b.begin() - 1;
    	if (pos == -1 or b[pos][1] <= x) {
    		std::cout << x << " ";
    	} else {
    		std::cout << b[pos][1] << " ";
    	}
    }
    std::cout << "\n";
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    int t;
    std::cin >> t;
    while (t--) 
        solve();

    return 0;
}
