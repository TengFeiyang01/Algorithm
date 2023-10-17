#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    i64 n, k;
    std::cin >> n >> k;
    std::vector<i64> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    
    // i64 ans = 1, j = 0;
	// while (k--) {
	// 	while (j < n and a[j] - j <= ans) j++;
	// 	ans += j;
	// }
    //假设当前最小值是x x前面有y个
   	//那么下一轮最小的数是x+y(如果没有被删除) 如果被删除了 那么(x+y)++, 再去比下一个 直到结尾
    //如果到结尾了， 那么每次删除的数+n


    a.push_back(1e18);
    i64 ans = 1, d = 1;
	for (int i = 0; i < n; ++i) {
		//放1e18的目的是让循环进行下去
		while (ans + d < a[i + 1]) {
			//每次跳的个数
			ans += d;
			k--;
			if (k == 0) break;
		}
		if (k == 0) break;
		d = i + 2;
	}

	std::cout << ans << "\n";
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
