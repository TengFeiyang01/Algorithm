#include <bits/stdc++.h>

const int inf = 0x3f3f3f3f;
using i64 = long long;
using PII = std::pair<int, int>;
const int N = 1e5 + 13;

void solve() {
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<int> s(m + 2);
    for (int i = 1; i <= m; ++i) {
    	std::cin >> s[i];
    }
    
    s[0] = -d + 1;
    s[m + 1] = n + 1;

    int sum = 0, ans = n + 1, cnt = 0;

    for (int i = 1; i <= m + 1; ++i) {
    	sum += (s[i] - s[i - 1] - 1) / d;
    }

   	//枚举去掉的是哪个
    for (int i = 1; i <= m; ++i) {
    	int res = sum;
    	res -= (s[i] - s[i - 1] - 1) / d;
    	res -= (s[i + 1] - s[i] - 1) / d;
    	res += (s[i + 1] - s[i - 1]  - 1) / d;
    	res += m - 1;
    	if (res < ans) {
    		ans = res;
    		cnt = 1;
    	} else if (res == ans) {
    		cnt += 1;
    	}
    }
    std::cout << ans << " " << cnt << "\n";
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
