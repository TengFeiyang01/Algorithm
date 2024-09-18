#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> l(n + 1), r(n + 1, 0);
    int head = -1;
    for (int i = 1; i <= n; ++i) {
    	int x;
    	std::cin >> x;
    	if (x == -1) {
    		head = i;
    	} else {
    		r[x] = i;
    	}
    }
    // std::cout << head  << " ";
    while (head != 0) {
    	std::cout << head << " ";
    	head = r[head];
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
