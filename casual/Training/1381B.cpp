#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n * 2), dp(n + 1);
    for (int i = 0; i < n * 2; ++i) {
    	std::cin >> a[i];
    }
    //性质：
    //如果一个数后面有一串比他小的数,那么这一段一定来自同一个序列
    //若是另一个 则另一个必然先于这个数出现
   	int last = 0, tmp = 1;
   	std::vector<int> p;
   	for (int i = 1; i < n * 2; ++i) {
   		if (a[i] < a[last]) tmp++;
   		else {
   			p.push_back(tmp);
   			tmp = 1;
   			last = i;
   		}
   	}
   	dp[0] = 1;
   	p.push_back(tmp);
   	for (int x : p) {
   		for (int j = n; j >= x; --j) {
   			dp[j] |= dp[j - x];
   		}
   	}
   	std::cout << (dp[n] ? "YES\n" : "NO\n");
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