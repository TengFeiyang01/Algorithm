#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

/*
	[1,n] 中的质数是肯定要问的。
	根据算术基本定理，x = p1^e1 * p2^e2 * ...
	知道质数还不够，还需要确定这些质数的幂次 e1,e2，才能确定 x。
	所以需要猜的数字是 [1,n] 中的质数，以及这些质数的平方、立方、……（不超过 n）。
*/

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> ans, st(n + 1);
    for (int i = 2; i <= n; ++i) {
    	if (st[i]) {
    		continue;
    	}
    	for (int j = i; j <= n; j *= i) {
    		ans.push_back(j);
    	}
    	for (int j = i * i; j <= n; j += i) {
    		st[j] = 1;
    	}
    }
    std::cout << ans.size() << "\n";
    for (auto x : ans) {
    	std::cout << x << " ";
    } 
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
