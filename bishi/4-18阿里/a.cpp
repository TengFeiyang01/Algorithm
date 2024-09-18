#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;

// 找规律题 好数分布的很密集 
// 通过背包dp 发现，除了本身是好数之外的都是2次，直接猜结论

void solve() {
	std::set<int> a;
	for (int i = 1; i <= 200000; ++i) {
		int j = i, s = 0;
		while (j) {
			s += j % 10;
			j /= 10;
		}
		if (i % s == 0) {
			a.insert(i);
		}
	}


    int T;
    std::cin >> T;
    while (T--) {
    	int n;
    	std::cin >> n;
    	if (a.count(n)) {
    		std::cout << 1 << "\n"; 
    	} else {
    		std::cout << 2 << "\n";
    	}
    }	
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();

    return 0;
}
