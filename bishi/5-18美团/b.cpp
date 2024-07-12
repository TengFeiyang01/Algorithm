#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::map<int, int> cnt;

    for (int i = 0, x; i < n; ++i) {
    	std::cin >> x;
    	cnt[x]++;
    }
    
    std::vector<int> p;
    for (auto [k, v] : cnt) {
    	p.push_back(v);
    }

    std::ranges::sort(p);
    int s = 0, k = 1;
    while (s < n) {
    	s += k;
    	k++;
    }

    std::vector<int> q(k - 1);
    for (int i = 1; i <= k - 1; ++i) {
    	q[i - 1] = i;
    }

    if (s != n or p != q) {
    	std::cout << "-1\n";
    } else {
    	std::cout << k - 1 << "\n";
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
